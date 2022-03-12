/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:51:12 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/03/12 15:35:14 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_loop(t_philo	*philo, t_philo	*philo2, t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&philo->forkmutex);
		printf("%dms %d has taken a fork\n", philo->time, philo->nbr);
		pthread_mutex_lock(&philo2->forkmutex);
		printf("%dms %d has taken a fork\n", philo->time, philo->nbr);
		pthread_mutex_lock(&philo->mealmutex);
		philo->last_meal = philo->time;
		printf("%dms %d  is eating\n", philo->time, philo->nbr);
		if (ft_sleep(data->time_to_eat, data, philo))
			return ;
		philo->n_t_eat += 1;
		if (philo->n_t_eat == data->n_of_times_to_eat)
		{
			data->n_eat += 1;
			pthread_mutex_unlock(&philo->forkmutex);
			pthread_mutex_unlock(&philo2->forkmutex);
			return ;
		}
		pthread_mutex_unlock(&philo->mealmutex);
		pthread_mutex_unlock(&philo->forkmutex);
		pthread_mutex_unlock(&philo2->forkmutex);
		printf("%dms %d  is sleeping\n", philo->time, philo->nbr);
		if (ft_sleep(data->time_to_sleep, data, philo))
			return ;
		printf("%dms %d is thinking\n", philo->time, philo->nbr);
		if (ft_sleep(data->time_to_eat - data->time_to_sleep, data, philo))
			return ;
		if (data->n_of_philos % 2 == 1)
			if (ft_sleep(data->time_to_eat, data, philo))
				return ;
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
		ft_sleep(data->time_to_die, data, philo);
		data->died = 1;
		return (0);
	}
	if (philo->nbr == data->n_of_philos)
		philo2 = philo - data->n_of_philos + 1;
	else
		philo2 = philo + 1;
	if (philo->nbr % 2 == 0)
		if (ft_sleep(data->time_to_eat, data, philo))
			return (0);
	if (philo->nbr == data->n_of_philos && data->n_of_philos % 2 == 1)
		if (ft_sleep((data->time_to_eat * 2), data, philo))
			return (0);
	philo_loop(philo, philo2, data);
	return (0);
}

t_philo	*create_philos(t_data *args)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(philos) * args->n_of_philos);
	if (!philos)
		return (0);
	i = 0;
	while (i < args->n_of_philos)
	{
		(philos + i)->nbr = i + 1;
		(philos + i)->last_meal = 0;
		(philos + i)->time = 0;
		args->philo = philos + i;
		if (pthread_mutex_init(&(philos + i)->forkmutex, NULL)
			|| pthread_mutex_init(&(philos + i)->mealmutex, NULL))
			return (0);
		if (pthread_create(&(philos + i)->thread, NULL, &philo_handler, args))
			return (0);
		if (pthread_detach((philos + i)->thread))
			return (0);
		usleep(100);
		i++;
	}
	return (philos);
}

int	main(int ac, char **av)
{
	t_data	*args;
	t_philo	*philo;

	if (!check_params(ac, av))
	{
		printf("Argument Error\n");
		return (1);
	}
	args = arg_to_struct(av);
	philo = create_philos(args);
	if (!philo)
		return (1);
	while (1)
	{
		if (args->died || args->n_eat == args->n_of_philos)
		{
			free(philo);
			usleep(10);
			if (args->died)
				printf("%dms %d has died\n", (philo + args->died - 1)->time,
					args->died);
			return (0);
		}
	}
	return (0);
}
