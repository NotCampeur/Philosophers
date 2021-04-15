/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:57:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/15 18:00:54 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*live(void *arg)
{
	t_phi	*phi;

	phi = (t_phi*)arg;
	phi->l_m_t = p_get_act_time(phi);
	while (*phi->sys->b_dead == false)
	{
		p_think(phi);
		p_eat(phi);
		if (p_check_hunger(phi) == true)
			return (NULL);
		p_sleep(phi);
	}
	return (NULL);
}

static void	start_simulation(t_phi *phi)
{
	unsigned int	i;
	pthread_t		d_check;
	
	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].tag = i;
		pthread_create(&(phi->sys->phi[i]), NULL, &live, (void*)&phi[i]);
		i++;
	}
	pthread_create(&d_check, NULL, p_death_check, (void*)phi);
	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		pthread_join(phi->sys->phi[i], NULL);
		i++;
	}
	pthread_join(d_check, NULL);
}

int			main(int ac, char *av[])
{
	t_sys	system;
	t_phi	*philosophers;

	philosophers = NULL;
	if (load_program(ac, av, &system, &philosophers) == EXIT_FAILURE)
		return (clean_exit(philosophers, EXIT_FAILURE));
	start_simulation(philosophers);
	clean_exit(philosophers, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
