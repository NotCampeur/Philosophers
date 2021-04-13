/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_timestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:02:34 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 17:51:17 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

size_t	p_str_len(char const *str)
{
	size_t	result;

	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}

void	p_put_timestamp(struct timeval *time, struct timeval *start_time
												, int index, char const *action)
{
	unsigned long long			time_in_ms;
	unsigned long long			start_time_in_ms;
	
	time_in_ms = (unsigned long long)(time->tv_sec) * 1000
				+ (unsigned long long)(time->tv_usec) / 1000;
	start_time_in_ms = (unsigned long long)(start_time->tv_sec) * 1000
					+ (unsigned long long)(start_time->tv_usec) / 1000;
	(void)time_in_ms;
	(void)start_time_in_ms;
	p_putull((unsigned long long)(start_time->tv_sec));
	write(1, " ", 1);
	p_putnbr(index);
	write(1, action, p_str_len(action));
}
