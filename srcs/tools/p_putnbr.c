/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_putnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:59:22 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 21:54:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

void	p_putchar(char c)
{
	write(1, &c, 1);
}

void	p_putl(long nb)
{
	if (nb < 0L)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10L)
		p_putl(nb / 10L);
	p_putchar((nb % 10L) + '0');
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
