/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_vitals_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:22:51 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 23:39:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_bool	g_end;

static t_bool	p_philo_is_dead(t_phi *phi)
{
	long			time;

	time = p_get_act_time(phi->sys->s_t);
	if (time - phi->l_m_t > phi->sys->args.t_to_die)
	{
		g_end = true;
		pthread_mutex_lock(phi->sys->m_write);
		printf(KRED"%ld %u died\n", time, phi->tag);
		pthread_mutex_unlock(phi->sys->m_write);
		return (true);
	}
	return (false);
}

static t_bool	p_philo_are_sated(t_phi *phi, t_bool done)
{
	if (done == true)
	{
		g_end = true;
		pthread_mutex_lock(phi->sys->m_write);
		printf(KGRN"Simulation lasted %ldms\n", p_get_act_time(phi->sys->s_t));
		pthread_mutex_unlock(phi->sys->m_write);
		return (true);
	}
	return (false);
}

void			*p_monitor_vitals_one(void *arg)
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
			return (NULL);
		i++;
		if (i >= phi->sys->args.phi_nb)
		{
			if (p_philo_are_sated(phi, done) == true)
				return (NULL);
			i = 0;
		}
	}
	return (NULL);
}
