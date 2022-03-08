/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:37:56 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/03/01 15:10:43 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void *handle(void *p)
{
	(void)p;
	return 0;
}

int	main(void)
{
	char	*str;
	char	*ftr;
	pthread_t t = 0;
	printf("%p\n", t);

	pthread_create(&t, NULL, &handle, NULL);

	str = "hello world";
	ftr = str + 5;
	printf("%p\n", t);
	return (0);
}
