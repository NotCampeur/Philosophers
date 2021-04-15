/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:28:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/15 13:20:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"
#include "philo_one_struct.h"

void	p_delay(t_phi *phi, long target_time)
{
	while (p_get_act_time(phi) < target_time)
		usleep(1);
}

long	p_get_act_time(t_phi *phi)
{
	long			result;
	struct timeval	act_time;

	gettimeofday(&act_time, NULL);
	result = (act_time.tv_sec - phi->sys->s_t.tv_sec) * 1000L
			+ (act_time.tv_usec - phi->sys->s_t.tv_usec) / 1000L;
	return (result);
}
