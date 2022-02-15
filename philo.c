/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:51:12 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/15 18:59:35 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*eating(t_data	*data)
{
	if (data->philo->last_meal)
	
	pthread_mutex_lock(data->philo->mutex);
	data->forks -= 2;
	printf("%d ms %d has take a fork\n", data->time, data->philo->nbr);
	printf("%d ms %d has take a fork\n", data->time, data->philo->nbr);
	printf("%d ms %d is eating\n", data->time, data->philo->nbr);
	data->philo->last_meal = data->time;
	data->time += data->time_to_eat;
	ft_sleep(data->time_to_eat);
	data->forks += 2;
	pthread_mutex_unlock(data->philo->mutex);
	return (data);
}

t_data	*sleeping(t_data	*data)
{
	pthread_mutex_lock(data->philo->mutex);
	printf("%d ms %d is sleeping\n", data->time, data->philo->nbr);
	data->time += data->time_to_sleep;
	ft_sleep(data->time_to_sleep);
	pthread_mutex_unlock(data->philo->mutex);
	return (data);
}

void	thinking(t_data *data)
{
	pthread_mutex_lock(data->philo->mutex);
	printf("%d ms %d is thinking\n", data->time, data->philo->nbr);
	ft_sleep(data->time_to_sleep);
	pthread_mutex_unlock(data->philo->mutex);
}

void	*philo_handler(void *args)
{
	t_data *data;
	t_philo	*philo;

	data = (t_data *)args;
	philo = data->philo;
	if (!(data->n_of_philos % 2))
		ft_sleep(data->time_to_eat);
	if (data->n_of_philos % 2 && data-philo->nbr == data->n_of_philos)
		ft_sleep(data->time_to_eat);
	while(1)
	{
		if (data->forks < (data->n_of_philos / 2))
			thinking(data);
		data = eating(data);
		data = sleeping(data);
	}
}

t_philo	*create_philos(t_data *args)
{
	int	i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * args->n_of_philos);
	i = 0;
	while (i < args->n_of_philos)
	{
		(philos + i)->nbr = i + 1;
		pthread_mutex_init((philos+i)->mutex, NULL);
		args->philo = philos + i;
		i++;
		if (pthread_create(philos->thread, NULL, &philo_handler, args))
			return (0);
	}
	return (philos);
}

void	philo(t_data *args)
{
	t_philo	*philo;
	philo = create_philos(args);
	int i = 0;
	while (i < args->n_of_philos)
	{
		pthread_join(*((philo+i)->thread), NULL);	
		pthread_mutex_destroy((philo+i)->mutex);
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	t_data	*args;
	
	if (!check_params(ac, av))
	{
		printf("Error!\n");
		return (1);
	}
	args = arg_to_struct(av);
	philo(args);
	return (0);
}
