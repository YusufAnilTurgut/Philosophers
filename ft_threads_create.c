/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:50 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/25 17:56:21 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_init(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	if (data->num_of_philo == 1)
	{
		pthread_create(&data->philo[0].thread, NULL, &only_one_philo, data);
		join_threads(data);
	}
	else
	{
		while (i < data->num_of_philo)
		{
			pthread_mutex_lock(&data->mutex_util);
			data->thread_index = i;
			pthread_mutex_unlock(&data->mutex_util);
			pthread_create(&data->philo[i++].thread, NULL, &routine, data);
			usleep(100);
		}
		pthread_create(&data->dead, NULL, &death, data);
		join_threads(data);
	}
}

void	join_threads(t_data *data)
{
	int	i;
	i = 0;
	while (i < data->num_of_philo)
		pthread_join(data->philo[i++].thread, NULL);
	pthread_join(data->dead, NULL);
}
