/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:57:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/14 16:21:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*live(void *arg)
{
	t_phi	*phi;
	long	p_time;

	phi = (t_phi*)arg;
	p_time = 0;
	while (p_get_act_time(phi) - p_time < phi->sys->args.t_to_die)
	{
		p_put_timestamp(phi, " has taken a fork\n", 0);
		p_eat(phi, &p_time);
		if (phi->sys->args.must_eat > 0)
		{
			phi->sys->args.must_eat--;
			if (phi->sys->args.must_eat == 0)
				return (NULL);
		}
		p_sleep(phi);
		p_think(phi);
	}
	p_put_timestamp(phi, " died\n", 1);
	return (NULL);
}

static void	test_thread(t_phi *phi)
{
	unsigned int	i;

	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].tag = i;
		pthread_create(&(phi->sys->phi[i]), NULL, &live, (void*)&phi[i]);
		i++;
	}
	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		pthread_join(phi->sys->phi[i], NULL);
		i++;
	}
}

int			main(int ac, char *av[])
{
	t_sys	system;
	t_phi	*philosophers;

	philosophers = NULL;
	if (load_program(ac, av, &system, &philosophers) == EXIT_FAILURE)
		return (clean_exit(philosophers, EXIT_FAILURE));
	test_thread(philosophers);
	clean_exit(philosophers, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
