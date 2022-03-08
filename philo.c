/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:51:12 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/03/08 12:26:14 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_handler(void *args)
{
	t_data	*data;
	t_philo	*philo;
	t_philo	*philo2;

	data = (t_data *)args;
	philo = data->philo;
	if (data->n_of_philos == 1)
	{
		philo->time += data->time_to_die;
		return (0);
	}
	if (philo->nbr == data->n_of_philos)
		philo2 = philo - data->n_of_philos + 1;
	else
		philo2 = philo + 1;
	if (philo->nbr % 2 == 0)
	{
		ft_sleep(data->time_to_eat, &(philo->time));
	}
	else if (philo->nbr == data->n_of_philos && data->n_of_philos % 2 == 1)
	{
		ft_sleep((data->time_to_eat * 2), &(philo->time));
	}               
	while (1)
	{
			pthread_mutex_lock(&philo->forkmutex);
			printf("%dms %d has taken a fork\n", philo->time, philo->nbr);
			pthread_mutex_lock(&philo2->forkmutex);
			printf("%dms %d has taken a fork\n", philo->time, philo->nbr);
			printf("%dms %d  is eating\n", philo->time, philo->nbr);
			philo->n_t_eat += 1;
			philo->last_meal = philo->time;
			if (philo->n_t_eat == data->n_of_times_to_eat)
				data->n_eat += 1;
			pthread_mutex_unlock(&philo->forkmutex);
			pthread_mutex_unlock(&philo2->forkmutex);
			ft_sleep(data->time_to_eat, &(philo->time));
			printf("%dms %d  is sleeping\n", philo->time, philo->nbr);
			ft_sleep(data->time_to_sleep, &(philo->time));
			printf("%dms %d is thinking\n", philo->time, philo->nbr);
			ft_sleep(data->time_to_eat - data->time_to_sleep, &(philo->time));
			if (data->n_of_philos % 2 == 1)
			{
				ft_sleep(data->time_to_eat, &(philo->time));
			}
	}
	return 0;
}
t_philo	*create_philos(t_data *args)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(philos) * args->n_of_philos);
	i = 0;
	while (i < args->n_of_philos)
	{
		(philos + i)->nbr = i + 1;
		(philos + i)->fork = 1;
		(philos + i)->time = 0;
		(philos + i)->last_meal = 0;
		i++;
	}
	i = 0;
	while (i <= args->n_of_philos)
	{
		if (i == args->n_of_philos)
		{
			if (pthread_create(&(philos + i)->thread, NULL, &philo_handler, args))
				break ;
			return (philos);
		}
		args->philo = philos + i;
		args->i = i;
		pthread_mutex_init(&(philos + i)->forkmutex, NULL);
		if (pthread_create(&(philos + i)->thread, NULL, &philo_handler, args))
			break ;
		usleep(1);
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	(void)ac;
	t_data	*args;
	t_philo	*philo;
	t_philo	*philo2;
	int  i;
	
	if (!check_params(ac, av))
	{
		printf("Error!\n");
		return (1);
	}
	args = arg_to_struct(av);
	philo = create_philos(args);
	if (!pthread_create())
	while(1)
	{
		i = 0;
		while (i < args->n_of_philos)
		{
			philo2 = philo + i;
			if ((philo2->time - philo2->last_meal) >= args->time_to_die)
			{    
				printf("%dms %d died\n", philo2->time, philo2->nbr);
				return (0);
			}
			i++;
		}
	}
	return (0);
}
