/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_routine.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:53:52 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/14 12:54:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_ROUTINE_H
# define PHILO_ONE_ROUTINE_H

/*
**	Return the microseconds elapsed between two timeval.
*/
long	get_elapsed_time(struct timeval *act_t, struct timeval *pre_t);

/*
**	Philisopher will sleep for t_sys->args->t_to_sleep microseconds.
*/
t_bool	p_sleep(t_phi *phi);

/*
**	Philisopher will eat and refresh the t_sys->args->t_to_die timer.
*/
t_bool	p_eat(t_phi *phi, long *prev_t);

/*
**	Philisopher will think.
*/
t_bool	p_think(t_phi *phi);

#endif
