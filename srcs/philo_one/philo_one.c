/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:57:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 10:43:02 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*live(void *arg)
{
	t_phi	*phi;

	phi = (t_phi*)arg;
	if (phi->l_m_t == 0L)
		phi->l_m_t = p_get_act_time(phi);
	p_eat(phi);
	if (phi->sys->b_dead == false && phi->sys->args.must_eat != 0)
		return (live(phi));
	return (NULL);
}

static void	start_simulation(t_phi *phi)
{
	unsigned int	i;
	pthread_t		monitor;

	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].tag = i;
		pthread_create(&(phi->sys->phi[i]), NULL, &live, (void*)&phi[i]);
		i += 2;
		usleep(50);
	}
	i = 1;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].tag = i;
		pthread_create(&(phi->sys->phi[i]), NULL, &live, (void*)&phi[i]);
		i += 2;
		usleep(50);
	}
	i = 0;
	pthread_create(&monitor, NULL, p_monitor_vitals, (void*)phi);
	pthread_join(monitor, NULL);
}

int			main(int ac, char *av[])
{
	t_sys			system;
	t_phi			*philosophers;
	unsigned int	i;

	i = 0;
	memset(&system, 0, sizeof(t_sys));
	philosophers = NULL;
	if (load_program(ac, av, &system, &philosophers) == EXIT_FAILURE)
		return (clean_exit(philosophers, EXIT_FAILURE));
	start_simulation(philosophers);
	while (i < philosophers->sys->args.phi_nb)
	{
		pthread_join(philosophers->sys->phi[i], NULL);
		i++;
	}
	clean_exit(philosophers, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
