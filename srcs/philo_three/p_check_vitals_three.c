/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_vitals_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:22:51 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 23:28:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*p_monitor_vitals(void *arg)
{
	t_phi	*phi;
	long	time;

	phi = (t_phi*)arg;
	while (1)
	{
		time = p_get_act_time(phi->sys->s_t);
		sem_wait(phi->sys->s_l_m_t);
		if (time - phi->l_m_t > phi->sys->args.t_to_die)
		{
			phi->sys->b_dead = true;
			sem_wait(phi->sys->s_write);
			printf(KRED"%ld %u died\n", time, phi->tag);
			sem_post(phi->sys->s_death);
			return (NULL);
		}
		sem_post(phi->sys->s_l_m_t);
		usleep(50);
	}
	return (NULL);
}
