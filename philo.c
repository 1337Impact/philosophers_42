/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:36:32 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/03 11:55:10 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*arg_to_struct(char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	data->n_of_philos = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	data->time_to_die = ft_atoi(av[4]);
	data->time_to_die = ft_atoi(av[5]);
	data->n_of_times_to_eat = -1;
	if (av[6])
		data->n_of_times_to_eat = ft_atoi(av[6]);
	return (data);
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
	return (0);
}
