/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:49:31 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 11:07:10 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_STRUCT_H
# define PHILO_ONE_STRUCT_H

typedef struct		s_sys
{
	t_args			args;
	t_phi			*phi;
	pthread_mutex_t	*fork;
}					t_sys;


#endif
