/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:57:01 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 19:57:21 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_data *data, int index)
{
	if (print_action(data, index, "is thinking"))
		return (1);
	return (0);
}



void* only_one_philo(void* v_data)
{
	t_data *data = (t_data *)v_data;
	print_action(data, 0, "has taken fork");
	smart_sleep(data -> time_to_die);
	printf("%-10lu   %d died", get_passed_time(data->start_time), data->philo[0].philo_id);
	return (NULL);
}

int	sleeping(t_data *data, int index)
{
	if (print_action(data, index, "is sleeping"))
		return (1);
	smart_sleep(data->time_to_sleep);
	return (0);
}

int eating(t_data *data, int index)
{

	if (is_death(data) == 0)
	{	
		pthread_mutex_lock(&data->forks[index]);
		pthread_mutex_lock(&data->forks[(index + 1) % data -> num_of_philo]);
		print_action(data, index, "has taken fork");
		print_action(data, index, "has taken fork");
		print_action(data, index, "eating");
		pthread_mutex_lock(&data->mutex_util);
		data -> philo[index].last_eat = get_time();
		data -> philo[index].meals++;
		pthread_mutex_unlock(&data->mutex_util);
		smart_sleep(data -> time_to_eat);
		pthread_mutex_unlock(&data->forks[index]);
		pthread_mutex_unlock(&data->forks[(index + 1) % data -> num_of_philo]);
		
	}
	else
		return (1);
	
	return 0;
}

void* routine(void* v_data)
{
	t_data *data = (t_data *)v_data;
	pthread_mutex_lock(&data ->mutex_util);
	int index = data -> thread_index;
	pthread_mutex_unlock(&data ->mutex_util);
	while (1)
	{
		if (data->num_must_eat != data->philo[index].meals)
		{
			if (is_death(data) == 1 || eating(data, index))
				break ;
			if (is_death(data) == 1|| sleeping(data, index))
				break ;
			if (is_death(data) == 1|| thinking(data, index))
				break ;
		}
		else
			break ;
	}
	return (NULL);
}