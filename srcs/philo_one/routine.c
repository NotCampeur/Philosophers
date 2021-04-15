/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:36:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/15 18:10:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_bool	p_sleep(t_phi *phi)
{
	if (*phi->sys->b_dead == true)
		return (false);
	p_put_timestamp(phi, " is sleeping\n", 0);
	p_delay(phi, p_get_act_time(phi) + phi->sys->args.t_to_sleep);
	return (true);
}

t_bool	p_take_forks(t_phi *phi, int left, int right)
{
	if (*phi->sys->b_dead == true)
		return false;
	if (left < right)
	{
		pthread_mutex_lock(&phi->sys->m_fork[left]);
		p_put_timestamp(phi, " has taken a fork\n", 0);
		if (*phi->sys->b_dead == true)
			return false;
		pthread_mutex_lock(&phi->sys->m_fork[right]);
		p_put_timestamp(phi, " has taken a fork\n", 0);
	}
	else
	{
		pthread_mutex_lock(&phi->sys->m_fork[right]);
		p_put_timestamp(phi, " has taken a fork\n", 0);
		if (*phi->sys->b_dead == true)
			return false;
		pthread_mutex_lock(&phi->sys->m_fork[left]);
		p_put_timestamp(phi, " has taken a fork\n", 0);
	}
	return (true);
}

t_bool	p_eat(t_phi *phi)
{
	int	left;
	int	right;

	left = (phi->tag != 0) ? phi->tag - 1 : phi->sys->nb_fork - 1;
	right = phi->tag;
	p_take_forks(phi, left, right);
	if (*phi->sys->b_dead == false)
	{
		p_put_timestamp(phi, " is eating\n", 0);
		phi->l_m_t = p_get_act_time(phi);
		p_delay(phi, phi->l_m_t + phi->sys->args.t_to_eat);
	}
	pthread_mutex_unlock(&phi->sys->m_fork[phi->tag]);
	if (phi->tag != 0)
		pthread_mutex_unlock(&phi->sys->m_fork[phi->tag - 1]);
	else
		pthread_mutex_unlock(&phi->sys->m_fork[phi->sys->nb_fork - 1]);
	return (true);
}

t_bool	p_think(t_phi *phi)
{
	p_put_timestamp(phi, " is thinking\n", 0);
	return (true);
}
