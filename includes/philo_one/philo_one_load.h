/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_load.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:04:38 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 12:13:40 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_LOAD_H
# define PHILO_ONE_LOAD_H

/*
**	Will check if every args are correct and will store them
*/
int	parse_args(int ac, char *av[]);

/*
**	Init the system by filling system->args, system->phi, system->fork
*/
int	load_program(int ac, char *av[], t_sys *system);

/*
**	Will free what need to be just before the exit.
**
**	Return ret
*/
int	clean_exit(t_sys *system, int ret);

#endif
