/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:28:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 12:28:53 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

long	p_get_act_time(struct timeval	start_time)
{
	struct timeval	act_time;

	gettimeofday(&act_time, NULL);
	return ((act_time.tv_sec - start_time.tv_sec) * 1000L
			+ (act_time.tv_usec - start_time.tv_usec) / 1000L);
}
