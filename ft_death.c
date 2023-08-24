/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:00:37 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 15:08:50 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meal(t_data *data, int index)
{
	pthread_mutex_lock(&data->mutex_util);
	if (data->philo[index].meals == data->num_must_eat)
	{
		pthread_mutex_unlock(&data->mutex_util);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_util);
	return (0);
}

int	philo_dead(t_data *data, int index)
{
	unsigned long	time;

	pthread_mutex_lock(&data->mutex_util);
	time = get_passed_time(data->philo[index].last_eat);
	if (time >= (unsigned long)data->time_to_die)
	{
		printf("%-10lu   %d %s\n",time, data->philo[index].philo_id,
			"died");
		data->is_philo_dead = 1;
		pthread_mutex_unlock(&data->mutex_util);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_util);
	return (0);
}

void	*death(void *void_data)
{
	int		i;
	t_data	*data;

	data = (t_data *)void_data;
	while (1)
	{
		i = 0;
		if (!is_dead(data) || !all_philos_eat(data))
			break ;
		if (meal(data, i))
			continue ;
		while (i < data->num_of_philo)
		{
			if (!all_philos_eat(data) || philo_dead(data, i))
				break ;
			i++;
		}
	}
	return (NULL);
}