/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:37:37 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 13:18:44 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_data *data, int index)
{
	if (print_action(data, index, "is thinking"))
		return (1);
	return (0);
}

int	sleeping(t_data *data, int index)
{
	if (print_action(data, index, "is sleeping") != 0)
		return (1);
	smart_sleep(data->time_to_sleep);
	return (0);
}

int	eating(t_data *data, int index)
{
	if (is_dead(data))
	{
		pthread_mutex_lock(&data->forks[index]);
		if (print_action(data, index, "has taken a fork"))
			return (1);
		pthread_mutex_lock(&data->forks[(index + 1) % data->num_of_philo]);
		if (print_action(data, index, "has taken a fork"))
			return (1);
		if (print_action(data, index, "is eating"))
			return (1);
		pthread_mutex_lock(&data->mutex_util);
		data->philo[index].meals++;
		data->philo[index].last_eat = get_time();
		pthread_mutex_unlock(&data->mutex_util);
		smart_sleep(data->time_to_eat);
		pthread_mutex_unlock(&data->forks[index]);
		pthread_mutex_unlock(&data->forks[(index + 1) % data->num_of_philo]);
	}
	else
		return (1);
	return (0);
}

void	*routine(void *void_data)
{
	int		index;
	t_data	*data;

	data = (t_data *)void_data;
	pthread_mutex_lock(&data->mutex_util);
	index = data->thread_index;
	pthread_mutex_unlock(&data->mutex_util);
	while (1)
	{
		if (data->num_must_eat != data->philo[index].meals)
		{
			if (!is_dead(data) || eating(data, index))
				break ;
			if (!is_dead(data) || sleeping(data, index))
				break ;
			if (!is_dead(data) || thinking(data, index))
				break ;
		}
		else
			break ;
	}
	return (0);
}

void	*one_philo(void *void_data)
{
	t_data	*data;

	data = (t_data *)void_data;
	print_action(data, 0, "has taken a fork");
	smart_sleep(data->time_to_die);
	printf("%-10lu   %d %s\n", get_passed_time(data->start_time),
		data->philo[0].philo_id, "died");
	return (NULL);
}