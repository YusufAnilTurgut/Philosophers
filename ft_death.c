/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:34:38 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 19:59:00 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_death(t_data *data, int i)
{
	unsigned long now = get_time();
	pthread_mutex_lock(&data->mutex_util);
	if(now - data->philo[i].last_eat >= (unsigned long)data->time_to_die)
	{
		printf("%-10lu   %d died", get_passed_time(data->start_time), data->philo[i].philo_id);
		data -> is_philo_dead = + 1;
		pthread_mutex_unlock(&data->mutex_util);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_util);
	return (0);
}



void* death(void* v_data)
{
	int i = 0;
	t_data *data = (t_data *)v_data;
	while (1)
	{
		i = 0;
		if (is_death(data) == 1 || all_philos_eat(data) == 1)
			break;
		while (i < data -> num_of_philo)
		{
			if(all_philos_eat(data) == 1 || philo_death(data, i))
				break;
			i++;
		}
	}
	return (NULL);
}