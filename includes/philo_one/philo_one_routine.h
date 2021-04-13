/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_routine.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:53:52 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 14:26:38 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_ROUTINE_H
# define PHILO_ONE_ROUTINE_H

/*
**	Return the microseconds elapsed between two timeval.
*/
unsigned int	get_elapsed_time(struct timeval *act_t, struct timeval pre_t);

/*
**	Philisopher will sleep for t_sys->args->t_to_sleep microseconds.
*/
t_bool	p_sleep(void);

/*
**	Philisopher will eat and refresh the t_sys->args->t_to_die timer.
*/
t_bool	p_eat(struct timeval act_t, struct timeval *prev_t);

/*
**	Philisopher will think.
*/
t_bool	p_think(void);

#endif
