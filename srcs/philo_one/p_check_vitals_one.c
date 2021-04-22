/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_vitals_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:22:51 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 17:55:15 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static t_bool	p_philo_is_dead(t_phi *phi, unsigned int index)
{
	long	time;

	time = p_get_act_time(phi[index].sys->s_t);
	if (time - phi[index].l_m_t > phi[index].sys->args.t_to_die)
	{
		phi[index].sys->b_dead = true;
		pthread_mutex_lock(phi[index].sys->m_write);
		printf(KRED"%ld %u died\n", time, phi[index].tag);
		return (true);
	}
	return (false);
}

static t_bool	p_philo_are_sated(t_phi *phi, t_bool done)
{
	if (done == true)
	{
		pthread_mutex_lock(phi->sys->m_write);
		printf(KGRN"Simulation lasted %ldms\n", p_get_act_time(phi->sys->s_t));
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
	return (NULL);
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
		if (p_philo_is_dead(phi, i) == true)
			return (p_massacre(phi));
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
