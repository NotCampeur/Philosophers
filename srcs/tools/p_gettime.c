/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_gettime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:28:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 12:43:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"
#include "philo_one_struct.h"

long	p_get_act_time(t_phi *phi)
{
	long			result;
	struct timeval	act_time;

	gettimeofday(&act_time, NULL);
	result = (act_time.tv_sec - phi->sys->s_t.tv_sec) * 1000L
			+ (act_time.tv_usec - phi->sys->s_t.tv_usec) / 1000L;
	return (result);
}
