/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:05:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/02/03 11:49:33 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_nbrlen(int nbr)
{
	int	i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	check_params(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (0);
	while (*(++av))
	{
		if (ft_nbrlen(ft_atoi(*av)) != ft_strlen(*av))
			return (0);
	}
	return (1);
}
