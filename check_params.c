/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:05:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/03/11 14:43:21 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		out = out * 10 + (str[i] - 48);
		i++;
	}
	if (str[i])
		return (-1);
	return (out);
}

int	check_params(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (0);
	if (ft_atoi(av[1]) == 0)
		return (0);
	while (*(++av))
	{
		if (ft_atoi(*av) == -1)
			return (0);
	}
	return (1);
}
