/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hunger_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:25:00 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 21:42:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

t_bool			p_check_hunger(int *must_eat)
{
	if (*must_eat > 0)
		(*must_eat)--;
	if (*must_eat == 0)
		return (true);
	return (false);
}
