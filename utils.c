/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:39:42 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/03/12 12:35:21 by mbenkhat         ###   ########.fr       */
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
	data->died = 0;
	data->n_of_times_to_eat = -1;
	data->n_eat = 0;
	if (av[5])
		data->n_of_times_to_eat = ft_atoi(av[5]);
	return (data);
}

int	ft_sleep(int time, t_data *data, t_philo *ph)
{
	int	t;

	t = 0;
	while (t < time)
	{
		if (data->died)
			return (1);
		usleep(1000);
		ph->time ++;
		t ++;
		if (ph->time - ph->last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&ph->mealmutex);
			data->died = ph->nbr;
			pthread_mutex_unlock(&ph->mealmutex);
			return (1);
		}
	}
	return (0);
}

void	free_trach(t_data *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < args->n_of_philos)
	{
		pthread_mutex_destroy(&(philo + i)->forkmutex);
		i++;
	}
	free(philo);
	free(args);
}
