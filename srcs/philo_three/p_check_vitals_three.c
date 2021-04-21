/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_vitals_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:22:51 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 18:17:03 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	p_philo_is_dead(t_phi *phi)
{
	long	time;

	time = p_get_act_time(phi->sys->s_t);
	sem_wait(phi->sys->s_l_m_t);
	if (time - phi->l_m_t > phi->sys->args.t_to_die)
	{
		phi->sys->b_dead = true;
		sem_wait(phi->sys->s_write);
		printf(KRED"%ld %u died\n", time, phi->tag);
		exit(EXIT_FAILURE);
	}
	sem_post(phi->sys->s_l_m_t);
}

static void	p_philo_are_sated(t_phi *phi, t_bool done)
{
	if (done == true)
	{
		sem_wait(phi->sys->s_l_m_t);
		phi->done_eating = true;
		sem_post(phi->sys->s_l_m_t);
		sem_wait(phi->sys->s_write);
		printf(KGRN"%ld %u is sated\n", p_get_act_time(phi->sys->s_t)
																	, phi->tag);
		sem_post(phi->sys->s_write);
		sem_post(phi->sys->s_goal);
	}
}

void		*p_monitor_vitals(void *arg)
{
	t_phi			*phi;
	t_bool			done;

	phi = (t_phi*)arg;
	while (1)
	{
		done = true;
		if (phi->sys->args.must_eat != 0)
			done = false;
		if (phi->done_eating == false)
		{
			p_philo_is_dead(phi);
			p_philo_are_sated(phi, done);
		}
		usleep(50);
	}
	return (NULL);
}
