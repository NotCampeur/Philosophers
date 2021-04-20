/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_tools.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:14:10 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 14:15:37 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_TOOLS_H
# define PHILO_ONE_TOOLS_H

/*
** sleep until the target time or philosopher running time is reach.
*/
void	p_delay_one(t_phi *phi, long target_time);

/*
** Check if philosophers are dead or if they are done eating.
*/
void	*p_monitor_vitals_one(void *arg);

#endif
