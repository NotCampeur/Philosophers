/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_len.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:37:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 13:35:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

int		p_nbr_len(long long int nbr)
{
	int	result;

	result = 1;
	nbr = (nbr < 0) ? nbr * -1 : nbr;
	while (nbr >= 10)
	{
		nbr /= 10;
		result++;
	}
	return (result);
}

size_t	p_str_len(char const *str)
{
	size_t	result;

	result = 0;
	if (str != NULL)
		while (str[result] != '\0')
			result++;
	return (result);
}
