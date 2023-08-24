/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:52:47 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 15:09:02 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_action(t_data *data, int index, char *str)
{
	pthread_mutex_lock(&data->mutex_util);
	if (data->num_must_eat == data->philo[index].meals)
	{
		pthread_mutex_unlock(&data->mutex_util);
		pthread_mutex_unlock(&data->forks[index]);
		pthread_mutex_unlock(&data->forks[(index + 1) % data->num_of_philo]);
		return (1);
	}
	if (data->is_philo_dead == 1)
	{
		pthread_mutex_unlock(&data->mutex_util);
		pthread_mutex_unlock(&data->forks[index]);
		pthread_mutex_unlock(&data->forks[(index + 1) % data->num_of_philo]);
		return (1);
	}
	printf("%-10lu   %d %s\n",get_passed_time(data->start_time),
		data->philo[index].philo_id, str);
	pthread_mutex_unlock(&data->mutex_util);
	return (0);
}