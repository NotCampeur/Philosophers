/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:57:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/12 12:40:40 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void *routine()
{
	printf("Okay this is a thread\n");
	return (NULL);
}

int	main(int ac, char *av[])
{
	pthread_t	thread;

	(void)ac;
	(void)av;
	pthread_create(&thread, NULL, &routine, NULL);
	pthread_join(thread, NULL);
	return (0);
}
