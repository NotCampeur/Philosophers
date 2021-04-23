/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:36:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/23 01:25:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	p_delay_three(t_phi *phi, long target_time)
{
	usleep(1000);
	if (p_get_act_time(phi->sys->s_t)
									< target_time && phi->sys->b_dead == false)
		p_delay_three(phi, target_time);
}

t_bool	p_sleep(t_phi *phi)
{
	if (phi->sys->b_dead == true)
		return (false);
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
												, " is sleeping\n");
	sem_post(phi->sys->s_write);
	p_delay_three(phi
				, p_get_act_time(phi->sys->s_t) + phi->sys->args.t_to_sleep);
	return (true);
}

t_bool	p_take_forks(t_phi *phi)
{
	if (phi->sys->b_dead == true)
		return (false);
	sem_wait(phi->sys->s_fork);
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n");
	sem_post(phi->sys->s_write);
	if (phi->sys->b_dead == true)
		return (false);
	sem_wait(phi->sys->s_fork);
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n");
	sem_post(phi->sys->s_write);
	return (true);
}

t_bool	p_eat(t_phi *phi)
{
	p_take_forks(phi);
	if (phi->sys->b_dead == false)
	{
		sem_wait(phi->sys->s_l_m_t);
		phi->l_m_t = p_get_act_time(phi->sys->s_t);
		sem_post(phi->sys->s_l_m_t);
		sem_wait(phi->sys->s_write);
		if (phi->sys->b_dead == false)
			p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " is eating\n");
		sem_post(phi->sys->s_write);
		p_delay_three(phi, phi->l_m_t + phi->sys->args.t_to_eat);
	}
	sem_post(phi->sys->s_fork);
	sem_post(phi->sys->s_fork);
	p_check_hunger_three(phi);
	return (true);
}

t_bool	p_think(t_phi *phi)
{
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " is thinking\n");
	sem_post(phi->sys->s_write);
	return (true);
}
