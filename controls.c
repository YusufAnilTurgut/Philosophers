/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:20:57 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/23 15:24:01 by yturgut          ###   ########.fr       */
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
		if (av[5])
		{
			if(ft_atoi(av[5]) < 0)
			{
				printf("Error: Wrong argument!\n");
				return (0);
			}
			data->num_must_eat =  ft_atoi(av[5]);
		}
		
	}
	else
		data->num_must_eat = -1;
	return 1;
}

void	destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->mutex_util);
}