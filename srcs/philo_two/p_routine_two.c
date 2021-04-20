/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:36:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 16:24:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	p_delay_two(t_phi *phi, long target_time)
{
	usleep(1000);
	if (p_get_act_time(phi->sys->s_t)
									< target_time && phi->sys->b_dead == false)
		p_delay_two(phi, target_time);
}

t_bool	p_sleep(t_phi *phi)
{
	if (phi->sys->b_dead == true)
		return (false);
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
												, " is sleeping\n", 0);
	sem_post(phi->sys->s_write);
	p_delay_two(phi, p_get_act_time(phi->sys->s_t) + phi->sys->args.t_to_sleep);
	return (true);
}

t_bool	p_take_forks(t_phi *phi, int left, int right)
{
	(void)left;
	(void)right;
	if (phi->sys->b_dead == true)
		return (false);
	sem_wait(phi->sys->s_fork);
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n", 0);
	sem_post(phi->sys->s_write);
	if (phi->sys->b_dead == true)
		return (false);
	sem_wait(phi->sys->s_fork);
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " has taken a fork\n", 0);
	sem_post(phi->sys->s_write);
	return (true);
}

t_bool	p_eat(t_phi *phi)
{
	int	left;
	int	right;

	left = (phi->tag != 0) ? phi->tag - 1 : phi->sys->nb_fork - 1;
	right = phi->tag;
	p_take_forks(phi, left, right);
	if (phi->sys->b_dead == false)
	{
		phi->l_m_t = p_get_act_time(phi->sys->s_t);
		sem_wait(phi->sys->s_write);
		if (phi->sys->b_dead == false)
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
	sem_wait(phi->sys->s_write);
	if (phi->sys->b_dead == false)
		p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
														, " is thinking\n", 0);
	sem_post(phi->sys->s_write);
	return (true);
}
