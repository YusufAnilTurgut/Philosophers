/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:20:57 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 20:02:04 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int control(int ac, char **av)
{
	int i = 0;
	int j = 1;
	
	if(ac != 5 && ac != 6)
	{
		printf("%sError: Wrong number of arguments!\n", "\e[31m");
		return (0);
	}
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if(!(av[j][i] >= '0' && av[j][i] <= '9'))
			{
				printf("%sError: Wrong argument!\n", "\e[31m");
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	is_death(t_data *data)
{
	pthread_mutex_lock(&data->mutex_util);
	if(data -> is_philo_dead == 1)
	{
		pthread_mutex_unlock(&data->mutex_util);
		return 1;
	}
	pthread_mutex_unlock(&data->mutex_util);
	return 0;
}

int all_philos_eat(t_data *data)
{
	int i = 0;
	while (i < data -> num_of_philo)
	{
		pthread_mutex_lock(&data->mutex_util);
		if (data->philo[i].meals != data -> num_must_eat )
		{
			pthread_mutex_unlock(&data->mutex_util);
			return 0;
		}
		pthread_mutex_unlock(&data->mutex_util);
		i++;
	}
	return 1;
}
