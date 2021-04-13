/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_part_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:28:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 17:27:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_PART_STRUCT_H
# define COMMON_PART_STRUCT_H

# include <pthread.h>

typedef struct	s_args
{
	unsigned int	phi_nb;
	unsigned int	t_to_die;
	unsigned int	t_to_eat;
	unsigned int	t_to_sleep;
	int				must_eat;
}				t_args;

typedef char	t_bool;
enum {false, true};

#endif
