/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nbr_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:37:21 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/16 10:41:18 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

int	nbr_len(long long int nbr)
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

int	str_len(char *str)
{
	int result;

	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}
