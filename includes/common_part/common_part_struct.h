/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_part_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:28:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/14 11:12:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_PART_STRUCT_H
# define COMMON_PART_STRUCT_H

# include <pthread.h>

typedef struct	s_args
{
	unsigned int	phi_nb;
	long			t_to_die;
	long			t_to_eat;
	long			t_to_sleep;
	int				must_eat;
}				t_args;

typedef char	t_bool;
enum {false, true};

#endif
