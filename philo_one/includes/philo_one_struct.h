/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:49:31 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 22:44:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

/*
**	This structure will store everything about the running programme
**
**	t_args			args keep the data sent by argv.
**	pthread_t		*phi store the address of each thread.
**	pthread_mutex_t	*m_fork contain a list of mutex used to protect the fork
**	pthread_mutex_t	*m_write refer to the mutex used to protect the output
**	unsigned int	nb_fork list the number of fork present.
**	struct timeval	s_t store the start time of the program.
*/
typedef struct		s_sys
{
	t_args			args;
	pthread_t		*phi;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	*m_write;
	unsigned int	nb_fork;
	struct timeval	s_t;
}					t_sys;

/*
**	This structure represent the entity known as philosopher.
**
**	unsigned int	tag is the index given to the philosopher.
**	t_sys			*sys is a reference to the t_sys structure.
**	long			l_m_t stock the "last_meal_time" of the philosopher.
*/
typedef struct		s_phi
{
	unsigned int	tag;
	t_sys			*sys;
	long			l_m_t;
	int				left;
	int				right;
}					t_phi;

#endif
