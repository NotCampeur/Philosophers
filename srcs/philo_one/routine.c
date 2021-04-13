/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:36:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 14:26:12 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

unsigned int	get_elapsed_time(struct timeval *act_t, struct timeval pre_t)
{
	unsigned int	result;
	time_t			act_sec;
	suseconds_t		act_usec;
	time_t			pre_sec;
	suseconds_t		pre_usec;
	
	gettimeofday(act_t, NULL);
	act_sec = act_t->tv_sec;
	act_usec = act_t->tv_usec;
	pre_sec = pre_t.tv_sec;
	pre_usec = pre_t.tv_usec;
	result = (act_sec - pre_sec) * 1000000;
	result += act_usec - pre_usec;
	return (result);
}

t_bool	p_sleep(void)
{

	return (EXIT_SUCCESS);
}

t_bool	p_eat(struct timeval act_t, struct timeval *prev_t)
{
	*prev_t = act_t;
	return (EXIT_SUCCESS);
}

t_bool	p_think(void)
{
	return (EXIT_SUCCESS);
}