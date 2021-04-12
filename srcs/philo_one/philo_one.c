/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:57:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/12 16:29:52 by ldutriez         ###   ########.fr       */
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
	pthread_t	thread[5];

	printf("t_bool size [%ld]\n", sizeof(t_bool));
	if (parse_args(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	for (int i=0; i < 5; i++)
	{
		pthread_create(&thread[i], NULL, &routine, NULL);
		printf("[%d] created\n", i);
	}
	
	for (int i=0; i < 5; i++)
		pthread_join(thread[i], NULL);
	return (0);
}
