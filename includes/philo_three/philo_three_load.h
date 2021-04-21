/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_load.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:04:38 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 15:59:11 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_LOAD_H
# define PHILO_THREE_LOAD_H

/*
**	Init the system by filling system->args, system->phi, system->fork
*/
int		load_program(int ac, char *av[], t_sys *system, t_phi **phi);

/*
**	Will free what need to be just before the exit.
**
**	Return ret
*/
void	clean_exit(t_phi *phi, int ret);

#endif
