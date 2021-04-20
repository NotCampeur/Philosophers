/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_tools.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:14:10 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 14:27:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_TOOLS_H
# define PHILO_TWO_TOOLS_H

/*
** sleep until the target time or philosopher running time is reach.
*/
void	p_delay_two(t_phi *phi, long target_time);

/*
** Check if philosophers are dead or if they are done eating.
*/
void	*p_monitor_vitals_two(void *arg);

#endif
