/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yturgut <yturgut@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:16:50 by yturgut           #+#    #+#             */
/*   Updated: 2023/08/24 20:21:35 by yturgut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **av)
{
	
	if(control(argc, av) == 0)
		return 1;
	t_data *data;
	data = malloc(sizeof(t_data ));
	if (get_data(data, av) == 0)
		return (1);

	mutex_init(data);	
	philo_init(data);
	thread_init(data);
	destroy(data);
	

	return 0;
}
