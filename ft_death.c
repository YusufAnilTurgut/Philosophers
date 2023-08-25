/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:34:38 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/25 18:12:36 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_ate(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_util);
	if(data -> philo[i].meals == data -> num_must_eat)
	{
		pthread_mutex_unlock(&data->mutex_util);
		return 1;
	}
	pthread_mutex_unlock(&data->mutex_util);
	return 0;
}

int philo_death(t_data *data, int i)
{
	unsigned long pass_time;
	pthread_mutex_lock(&data->mutex_util);
	pass_time = get_passed_time(data -> philo[i].last_eat);
	if(pass_time >= (unsigned long)data->time_to_die)
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
		if (is_ate(data, i) == 1 )
			continue ;
		while (i < data -> num_of_philo)
		{
			if(all_philos_eat(data) == 1 || philo_death(data, i))
				break;
			i++;
		}
	}
	return (NULL);
}
