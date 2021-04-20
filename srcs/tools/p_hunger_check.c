/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hunger_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:25:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 15:44:42 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

t_bool			p_check_hunger(int *must_eat)
{
	if (*must_eat > 0)
		(*must_eat)--;
	return (false);
}
