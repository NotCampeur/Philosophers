/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hunger_check_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:25:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 22:58:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_bool			p_check_hunger_three(t_phi *phi)
{
	if (phi->sys->args.must_eat > 0)
	{
		phi->sys->args.must_eat--;
		if (phi->sys->args.must_eat == 0)
		{
			sem_wait(phi->sys->s_write);
			p_put_timestamp(p_get_act_time(phi->sys->s_t), phi->tag
													, " is sated\n", 0);
			sem_post(phi->sys->s_write);
			sem_post(phi->sys->s_goal);
		}
	}
	return (false);
}
