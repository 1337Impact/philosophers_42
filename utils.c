/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:39:42 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/03/11 11:08:06 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*arg_to_struct(char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	data->n_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->time = 0;
	data->died = 0;
	data->n_of_times_to_eat = -1;
	data->n_eat = 0;
	if (av[5])
		data->n_of_times_to_eat = ft_atoi(av[5]);
	return (data);
}

int	ft_sleep(int time, t_data *data)
{
	int	t;
	t_philo	*ph;
	struct timeval	t1;
	

	t = 0;
	ph = data->philo;
	while(t < time)
	{
		usleep(10000);
		gettimeofday(&t1, NULL);
		data->time = t1.tv_usec / 1000 - data->init_time;
		// if (ph->last_meal + data->time_to_die >= data->time)
		t += 10;
	}
	return (0);
}