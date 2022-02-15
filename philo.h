/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:36:43 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/14 14:27:44 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_philo
{
	int			nbr;
	int			fork;
	pthread_t	*thread;
	pthread_mutex_t	*mutex;
}			t_philo;

typedef struct s_data
{
	int n_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int n_of_times_to_eat;
	int	time;
	t_philo	*philo;
}			t_data;

int	check_params(int ac, char **av);
t_data	*arg_to_struct(char **av);
int ft_strlen(char *str);
int	ft_atoi(const char *str);

#endif