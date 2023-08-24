/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:21:50 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 15:23:21 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_data *data, int index)
{
	printf("%d is : Sleeping\n",index);
	smart_sleep(data->time_to_sleep);
}

void	thinking(t_data *data, int index)
{
	
}