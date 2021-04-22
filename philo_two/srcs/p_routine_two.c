/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:36:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 23:47:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

extern t_bool	g_end;

void	p_delay_two(t_phi *phi, long target_time)
{
	usleep(1000);
	if (p_get_act_time(phi->sys->s_t) < target_time && g_end == false)
		p_delay_two(phi, target_time);
}

t_bool	p_sleep(t_phi *phi)
{
	long	a_t;

	a_t = p_get_act_time(phi->sys->s_t);
	if (g_end == true)
		return (false);
	sem_wait(phi->sys->s_write);
	if (g_end == false)
		p_put_timestamp(a_t, phi->tag, " is sleeping\n", 0);
	sem_post(phi->sys->s_write);
	if (phi->l_m_t + phi->sys->args.t_to_die > a_t + phi->sys->args.t_to_sleep)
		p_delay_two(phi, a_t + phi->sys->args.t_to_sleep);
	else
		p_delay_two(phi, phi->l_m_t + phi->sys->args.t_to_die);
	return (true);
}

t_bool	p_take_forks(t_phi *phi)
{
	if (g_end == true)
		return (false);
	sem_wait(phi->sys->s_fork);
	if (g_end == true)
		return (sem_post(phi->sys->s_fork));
	sem_wait(phi->sys->s_write);
	if (g_end == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n", 0);
	sem_post(phi->sys->s_write);
	if (g_end == true)
		return (sem_post(phi->sys->s_fork));
	sem_wait(phi->sys->s_fork);
	if (g_end == true)
		return (sem_post(phi->sys->s_fork) + sem_post(phi->sys->s_fork));
	sem_wait(phi->sys->s_write);
	if (g_end == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n", 0);
	sem_post(phi->sys->s_write);
	return (true);
}

t_bool	p_eat(t_phi *phi)
{
	if (g_end == false)
	{
		if (p_take_forks(phi) == false)
			return (false);
		phi->l_m_t = p_get_act_time(phi->sys->s_t);
		if (g_end == true)
			return (sem_post(phi->sys->s_fork) + sem_post(phi->sys->s_fork));
		sem_wait(phi->sys->s_write);
		if (g_end == false)
			p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " is eating\n", 0);
		sem_post(phi->sys->s_write);
		p_delay_two(phi, phi->l_m_t + phi->sys->args.t_to_eat);
	}
	sem_post(phi->sys->s_fork);
	sem_post(phi->sys->s_fork);
	p_check_hunger(&phi->sys->args.must_eat);
	return (true);
}

t_bool	p_think(t_phi *phi)
{
	if (g_end == true)
		return (false);
	sem_wait(phi->sys->s_write);
	if (g_end == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
														, " is thinking\n", 0);
	sem_post(phi->sys->s_write);
	return (true);
}
