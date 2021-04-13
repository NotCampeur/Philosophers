/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:00:01 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 17:56:05 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static long long	static_ft_atoll(char *str)
{
	long long	result;
	long long	index;
	long long	sign;

	if (str == NULL)
		return (0);
	result = 0;
	index = 0;
	sign = 1;
	while (str[index] == ' ')
		index++;
	if (str[index] == '+')
		index++;
	else if (str[index] == '-')
	{
		index++;
		sign *= -1;
	}
	while (str[index] != '\0' && (str[index] >= '0' && str[index] <= '9'))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

static t_bool		is_integer(char *str[])
{
	int			index;
	long long	value;

	index = 1;
	value = 0;
	while (str[index] != NULL)
	{
		value = static_ft_atoll(str[index]);
		if (str_len(str[index]) > 11 || value > INT_MAX || value < INT_MIN)
			return (false);
		index++;
	}
	return (true);
}

static t_bool		is_suitable(char *str[])
{
	int	i;
	int	c;

	i = 1;
	while (str[i] != NULL)
	{
		c = 0;
		while (str[i][c] != '\0')
		{
			if (str[i][c] < 48 || str[i][c] > 58)
				return (false);
			c++;
		}
		i++;
	}
	return (true);
}

int					parse_args(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
	{
		write(2, "Invalid number of arguments\n", 29);
		return (EXIT_FAILURE);
	}
	if (is_suitable(av) == false)
	{
		write(2, "Arguments are not only composed by digits\n", 43);
		return (EXIT_FAILURE);
	}
	if (is_integer(av) == false)
	{
		write(2, "Arguments are not int\n", 23);
		return (EXIT_FAILURE);
	}
	if (p_atoi(av[1]) < 1 || p_atoi(av[2]) < 60 || p_atoi(av[3]) < 60
														|| p_atoi(av[4]) < 60)
	{
		write(2, "Arguments are not suitable\n", 28);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
