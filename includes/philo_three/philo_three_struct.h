/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:44:19 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 23:19:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_STRUCT_H
# define PHILO_THREE_STRUCT_H

/*
**	This structure will store everything about the running programme
**
**	t_args			args keep the data sent by argv.
**	pthread_t		*phi store the address of each thread.
**	sem_t			*s_fork contain a semaphore pointer used to protect the fork
**	sem_t			*s_write refer to the semaphore used to protect the output
**	sem_t			*s_l_m_t refer to the semaphore used to protect the l_m_t
**	sem_t			*s_goal refer to the semaphore used to check the goal
**	unsigned int	nb_fork list the number of fork present.
**	struct timeval	s_t store the start time of the program.
**	t_bool			b_dead will keep the track of philosophers' vitals.
*/
typedef struct		s_sys
{
	t_args			args;
	sem_t			*s_fork;
	sem_t			*s_write;
	sem_t			*s_l_m_t;
	sem_t			*s_goal;
	sem_t			*s_death;
	unsigned int	nb_fork;
	struct timeval	s_t;
	t_bool			b_dead;
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
	pid_t			pid;
}					t_phi;

#endif
