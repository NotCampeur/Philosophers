/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_routine.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:53:52 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 17:23:54 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_ROUTINE_H
# define PHILO_THREE_ROUTINE_H

/*
**	Philisopher will sleep for t_sys->args->t_to_sleep microseconds.
*/
t_bool	p_sleep(t_phi *phi);

/*
**	Philisopher will try to grab forks
*/
t_bool	p_take_forks(t_phi *phi);

/*
**	Philisopher will eat and refresh the t_sys->args->t_to_die timer.
*/
t_bool	p_eat(t_phi *phi);

/*
**	Philisopher will think.
*/
t_bool	p_think(t_phi *phi);

#endif
