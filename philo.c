/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:51:12 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/03/11 10:43:08 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_loop(t_philo	*philo, t_philo	*philo2, t_data *data)
{
	while (1)
	{
		// pthread_mutex_lock(&philo->forkmutex);
		printf("%dms %d has taken a fork\n", data->time, philo->nbr);
		pthread_mutex_lock(&philo2->forkmutex);
		printf("%dms %d has taken a fork\n", data->time, philo->nbr);
		philo->last_meal = data->time;
		printf("%dms %d  is eating\n", data->time, philo->nbr);
		// pthread_mutex_unlock(&data->meal_mutex);
		if (ft_sleep(data->time_to_eat, data))
			return ;
		pthread_mutex_unlock(&philo->forkmutex);
		pthread_mutex_unlock(&philo2->forkmutex);
		printf("%dms %d  is sleeping\n", data->time, philo->nbr);
		if (ft_sleep(data->time_to_eat, data))
			return ;
		printf("%dms %d is thinking\n", data->time, philo->nbr);
		if (ft_sleep(data->time_to_eat - data->time_to_sleep, data))
			return ;
		if (data->n_of_philos % 2 == 1)
		{
			if (ft_sleep(data->time_to_eat, data))
				return ;
		}
	}
}


void	*philo_handler(void *args)
{
	t_data	*data;
	t_philo	*philo;
	t_philo	*philo2;

	data = (t_data *)args;
	philo = data->philo;
	if (data->n_of_philos == 1)
	{
		data->died = 1;
		ft_sleep(data->time_to_die, data);
		return (0);
	}
	if (philo->nbr == data->n_of_philos)
		philo2 = philo - data->n_of_philos + 1;
	else
		philo2 = philo + 1;
	if (philo->nbr % 2 == 0)
	{
		ft_sleep(data->time_to_eat, data);
	}
	else if (philo->nbr == data->n_of_philos && data->n_of_philos % 2 == 1)
	{
		ft_sleep((data->time_to_eat * 2), data);
	}
	philo_loop(philo, philo2, data);
	return (0);
}


t_philo	*create_philos(t_data *args)
{
	int		i;
	t_philo	*philos;
	struct timeval	t;

	philos = malloc(sizeof(philos) * args->n_of_philos);
	i = 0;
	pthread_mutex_init(&(args->meal_mutex), NULL);
	gettimeofday(&t, NULL);
	args->init_time = t.tv_usec / 1000;
	while (i < args->n_of_philos)
	{
		(philos + i)->nbr = i + 1;
		(philos + i)->last_meal = 0;
		args->philo = philos + i;
		args->i = i;
		if (pthread_mutex_init(&(philos + i)->forkmutex, NULL))
			return 0;
		if (pthread_create(&(philos + i)->thread, NULL, &philo_handler, args))
			return 0;
		i++;
	}
	return (philos);
}


int	main(int ac, char **av)
{
	(void)ac;
	t_data	*args;
	t_philo	*philo;
	
	if (!check_params(ac, av))
	{
		printf("Error!\n");
		return (1);
	}
	args = arg_to_struct(av);
	philo = create_philos(args);
	if (!philo)
		return (1);
	while(1)
	{
		if (args->died)
		{
			printf("%dms %d has died\n", args->time, args->died);
			return (0);
		}
	}
	return (0);
}
