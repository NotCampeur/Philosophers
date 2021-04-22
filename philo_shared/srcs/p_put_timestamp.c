/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_timestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:02:34 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 17:49:05 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

static char	*p_strjoin(char const *str1, char const *str2)
{
	int		index;
	int		str1_len;
	char	*result;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	str1_len = p_str_len(str1);
	index = 0;
	result = (char*)malloc(sizeof(char) * (str1_len + p_str_len(str2) + 1));
	if (result == NULL)
		return (NULL);
	memset(result, 0, (str1_len + p_str_len(str2) + 1));
	while (index < str1_len)
	{
		result[index] = str1[index];
		index++;
	}
	index = 0;
	while (str2 != NULL && str2[index] != '\0')
	{
		result[index + str1_len] = str2[index];
		index++;
	}
	return (result);
}

static char	*p_itoa(long long nb)
{
	char		*result;
	int			i;

	i = p_nbr_len(nb);
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	while (i != 0)
	{
		i--;
		result[i] = (nb % 10 + 48);
		nb /= 10;
	}
	return (result);
}

void		p_put_timestamp(long act_time, unsigned int id
											, char const *action, char color)
{
	char	*tmp;
	void	*pointer;
	char	*msg;

	tmp = p_itoa(id);
	msg = p_strjoin(" ", tmp);
	free(tmp);
	pointer = msg;
	msg = p_strjoin(msg, action);
	free(pointer);
	tmp = p_itoa(act_time);
	pointer = msg;
	msg = p_strjoin(tmp, msg);
	free(pointer);
	free(tmp);
	pointer = msg;
	msg = (color == 1) ? p_strjoin(KRED, msg) : p_strjoin(KNRM, msg);
	free(pointer);
	write(1, msg, p_str_len(msg));
	free(msg);
}
