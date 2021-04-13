/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:59:22 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 16:04:27 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

void	p_putchar(char c)
{
	write(1, &c, 1);
}

void	p_putull(unsigned long long nb)
{
	if (nb >= 10ull)
		p_putnbr(nb / 10ull);
	p_putchar((nb % 10ull) + 48ull);
}

void	p_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
		p_putnbr(nb / 10);
	p_putchar((nb % 10) + '0');
}
