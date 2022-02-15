/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:51:12 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/15 11:20:54 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_handler(void *args)
{
	t_data *data;
	t_philo	*philo;

	data = (t_data *)args;
	philo = data->philo;
	while (1)
	{
		if (philo->fork && philo)
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
		(&philos[i])->nbr = i + 1;
		(&philos[i])->fork = 1;
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
		pthread_join(*(philo->thread), NULL);	
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
