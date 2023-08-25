/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:16:15 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/25 16:47:08 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_data(t_data *data, char **av)
{
	data->num_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if(data->num_of_philo < 1)
	{
		printf("Error: Wrong argument!\n");
		return (0);
	}
	if (av[5])
	{
		if(ft_atoi(av[5]) < 0)
		{
			printf("Error: Wrong argument!\n");
			return (0);
		}
		data->num_must_eat =  ft_atoi(av[5]);
	}
	else
		data->num_must_eat = -1;
	return 1;
}

void	mutex_init(t_data *data)
{
	int i;
	i = 0;
	data -> forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);

	while (i < data -> num_of_philo)
	{
		pthread_mutex_init(&data -> forks[i], NULL);
		i++;
	}
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
	data->is_philo_dead = 0;
	data->thread_index = 0;
}