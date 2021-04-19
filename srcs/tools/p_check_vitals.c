/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_vitals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:22:51 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/19 11:03:23 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

t_bool			p_check_hunger(t_phi *phi)
{
	if (phi->sys->args.must_eat > 0)
		phi->sys->args.must_eat--;
	return (false);
}

static t_bool	p_philo_is_dead(t_phi *phi)
{
	long	time;

	time = p_get_act_time(phi);
	if (time - phi->l_m_t > phi->sys->args.t_to_die)
	{
		phi->sys->b_dead = true;
		pthread_mutex_lock(phi->sys->m_write);
		printf(KRED"%ld %u died\n", time, phi->tag);
		return (true);
	}
	return (false);
}

static void		*p_massacre(t_phi *phi)
{
	unsigned int	i;

	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].sys->b_dead = true;
		i++;
	}
	pthread_mutex_unlock(phi->sys->m_write);
	return (NULL);
}

void			*p_monitor_vitals(void *arg)
{
	unsigned int	i;
	t_phi			*phi;
	t_bool			done;

	i = 0;
	phi = (t_phi*)arg;
	while (i < phi->sys->args.phi_nb)
	{
		done = true;
		if (phi[i].sys->args.must_eat != 0)
			done = false;
		if (p_philo_is_dead(&phi[i]) == true)
			return (p_massacre(phi));
		i++;
		if (i >= phi->sys->args.phi_nb)
		{
			if (done == true)
			{
				printf(KGRN"Simulation lasted %ldms\n", p_get_act_time(phi));
				return (p_massacre(phi));
			}
			i = 0;
			usleep(1000);
		}
	}
	return (NULL);
}
