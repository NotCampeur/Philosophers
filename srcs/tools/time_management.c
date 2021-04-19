/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:28:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/19 11:01:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"
#include "philo_one_struct.h"

void	p_delay(t_phi *phi, long target_time)
{
	usleep(1000);
	if (p_get_act_time(phi) < target_time && phi->sys->b_dead == false)
		p_delay(phi, target_time);
}

long	p_get_act_time(t_phi *phi)
{
	struct timeval	act_time;

	gettimeofday(&act_time, NULL);
	return ((act_time.tv_sec - phi->sys->s_t.tv_sec) * 1000L
			+ (act_time.tv_usec - phi->sys->s_t.tv_usec) / 1000L);
}
