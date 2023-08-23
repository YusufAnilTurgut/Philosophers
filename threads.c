/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:50 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/23 15:22:43 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_data *data)
{
	int i;
	i = 0;
	data -> forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);

	while (i < data -> num_of_philo)
		pthread_mutex_init(&data -> forks[i++], NULL);
	pthread_mutex_init(&data->mutex_util, NULL);
}

void	philo_init(t_data *data)
{
	int i = 0;
	data -> philo = malloc(sizeof(t_philo) * data -> num_of_philo);
	i = 0;
	while (i < data->num_of_philo)
	{	
		data -> philo[i].philo_id = i + 1;
		data -> philo[i].meals = 0;
		data -> philo[i].last_eat = get_time();
		i++;
	}
	data->philo_dead = 0;
	data->thread_index = 0;
}