/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:36:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 23:41:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

extern t_bool	g_end;

void	p_delay_one(t_phi *phi, long target_time)
{
	usleep(1000);
	if (p_get_act_time(phi->sys->s_t) < target_time && g_end == false)
		p_delay_one(phi, target_time);
}

t_bool	p_sleep(t_phi *phi)
{
	long	a_t;

	a_t = p_get_act_time(phi->sys->s_t);
	if (g_end == true)
		return (false);
	pthread_mutex_lock(phi->sys->m_write);
	if (g_end == false)
		p_put_timestamp(a_t, phi->tag, " is sleeping\n", 0);
	pthread_mutex_unlock(phi->sys->m_write);
	if (phi->l_m_t + phi->sys->args.t_to_die > a_t + phi->sys->args.t_to_sleep)
		p_delay_one(phi, a_t + phi->sys->args.t_to_sleep);
	else
		p_delay_one(phi, phi->l_m_t + phi->sys->args.t_to_die);
	return (true);
}

t_bool	p_take_forks(t_phi *phi)
{
	if (g_end == true)
		return (false);
	pthread_mutex_lock(&phi->sys->m_fork[phi->left]);
	if (g_end == true)
		return (pthread_mutex_unlock(&phi->sys->m_fork[phi->left]));
	pthread_mutex_lock(phi->sys->m_write);
	if (g_end == false && phi->sys->args.must_eat != 0)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n", 0);
	pthread_mutex_unlock(phi->sys->m_write);
	if (g_end == true)
		return (pthread_mutex_unlock(&phi->sys->m_fork[phi->left]));
	pthread_mutex_lock(&phi->sys->m_fork[phi->right]);
	if (g_end == true)
	{
		return (pthread_mutex_unlock(&phi->sys->m_fork[phi->left])
				+ pthread_mutex_unlock(&phi->sys->m_fork[phi->right]));
	}
	pthread_mutex_lock(phi->sys->m_write);
	if (g_end == false && phi->sys->args.must_eat != 0)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n", 0);
	pthread_mutex_unlock(phi->sys->m_write);
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
		{
			return (pthread_mutex_unlock(&phi->sys->m_fork[phi->left])
						+ pthread_mutex_unlock(&phi->sys->m_fork[phi->right]));
		}
		pthread_mutex_lock(phi->sys->m_write);
		if (g_end == false && phi->sys->args.must_eat != 0)
			p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " is eating\n", 0);
		pthread_mutex_unlock(phi->sys->m_write);
		p_delay_one(phi, phi->l_m_t + phi->sys->args.t_to_eat);
		pthread_mutex_unlock(&phi->sys->m_fork[phi->left]);
		pthread_mutex_unlock(&phi->sys->m_fork[phi->right]);
	}
	return (true);
}

t_bool	p_think(t_phi *phi)
{
	if (g_end == true)
		return (false);
	pthread_mutex_lock(phi->sys->m_write);
	if (g_end == false && phi->sys->args.must_eat != 0)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
														, " is thinking\n", 0);
	pthread_mutex_unlock(phi->sys->m_write);
	return (true);
}
