/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:36:32 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/03 19:38:39 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*handler(void *params);

philo_t	*create_philos(t_data *args)
{
	int	i;
	philo_t	*philos;
	
	philos = malloc(sizeof(philo_t) * args->n_of_philos);
	i = 1;
	while (i <= args->n_of_philos)
	{
		philos->nbr = i;
		pthread_create(philos->thread, NULL, &handler, args);
	}
	return (philos);
}

int	philo(t_data *args)
{
	
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