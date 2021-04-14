/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:49:31 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/14 13:11:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

typedef struct		s_sys
{
	t_args			args;
	pthread_t		*phi;
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_write;
	unsigned int	nb_fork;
	struct timeval	s_t;
}					t_sys;

typedef struct		s_phi
{
	unsigned int	tag;
	t_sys			*sys;
}					t_phi;

#endif
