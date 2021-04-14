/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:36:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	get_elapsed_time(struct timeval *act_t, struct timeval *pre_t)
{
	long result;

	gettimeofday(act_t, NULL);
	result = (act_t->tv_sec - pre_t->tv_sec) * 1000L
			+ ((act_t->tv_usec) - (pre_t->tv_usec)) / 1000L;
	return (result);
}

t_bool	p_sleep(t_phi *phi)
{
	p_put_timestamp(phi, " is sleeping\n", 0);
	return (EXIT_SUCCESS);
}

t_bool	p_eat(t_phi *phi, long *prev_t)
{
	p_put_timestamp(phi, " is eating\n", 0);
	*prev_t = p_get_act_time(phi);
	return (EXIT_SUCCESS);
}

t_bool	p_think(t_phi *phi)
{
	p_put_timestamp(phi, " is thinking\n", 0);
	return (EXIT_SUCCESS);
}
