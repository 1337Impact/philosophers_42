/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:36:43 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/03 19:33:06 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_data
{
	int n_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int n_of_times_to_eat;
	int	time;
}			t_data;

typedef struct philo_s
{
	int			nbr;
	pthread_t	*thread;
}			philo_t;

int	check_params(int ac, char **av);

#endif