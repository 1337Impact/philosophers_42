/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:36:32 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/04 20:16:44 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_data	*params)
{
	pthread_mutex_lock(params->philo->mutex);
	printf("%dms %d has taken a fork", params->time, params->philo->nbr);
	printf("%dms %d has taken a fork", params->time, params->philo->nbr);
	printf("%dms %d is eating", params->time, params->philo->nbr);
	usleep(params->time_to_eat * 1000);
	params->time += params->time_to_eat;
	pthread_mutex_unlock(params->philo->mutex);
}

void	sleeping(t_data	*params)
{
	pthread_mutex_lock(params->philo->mutex);
	printf("%dms %d is sleeping", params->time, params->philo->nbr);
	usleep(params->time_to_sleep * 1000);
	params->time += params->time_to_sleep;
	pthread_mutex_unlock(params->philo->mutex);
}

void	*philo_handler(t_data *params)
{
	if (params->philo->nbr % 2 == 0)
	{
		eating(params);
		sleeping(params);
	}
	else
		printf("%dms %d is thinking", params->time, params->philo->nbr);
	
}

t_philo	*create_philos(t_data *args)
{
	int	i;
	t_philo	*philos;
	
	philos = malloc(sizeof(t_philo) * args->n_of_philos);
	i = 1;
	while (i <= args->n_of_philos)
	{
		(&philos[i - 1])->nbr = i++;
		if (pthread_create(philos->thread, NULL, &philo_handler, args))
			return (0);
	}
	return (philos);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_data	*data;
	
	if (!check_params(ac, av));
	{
		printf("Error!\n");
		return (1);
	}
	data = arg_to_struct(av);
	philo(data);
	return (0);
}
