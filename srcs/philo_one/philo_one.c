/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:57:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 12:41:59 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*routine(void *arg)
{
	(void)arg;
	printf("Okay this is a thread\n");
	return (NULL);
}

static void	test_thread(void)
{
	pthread_t	thread[5];
	int			i;

	i = 0;
	while (i < 5)
	{
		printf("[%d] created\n", i);
		pthread_create(&thread[i], NULL, &routine, NULL);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

int			main(int ac, char *av[])
{
	t_sys	system;
	
	if (load_program(ac, av, &system) == EXIT_FAILURE)
		return (clean_exit(&system, EXIT_FAILURE));
	test_thread();
	clean_exit(&system, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
