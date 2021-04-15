/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_timestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:02:34 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/15 13:20:24 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"
#include "philo_one_struct.h"

size_t		p_str_len(char const *str)
{
	size_t	result;

	result = 0;
	if (str != NULL)
		while (str[result] != '\0')
			result++;
	return (result);
}

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
	long long	mem;

	mem = nb;
	i = 1;
	while (mem /= 10)
		i++;
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

void		p_put_timestamp(t_phi *phi, char const *action, char color)
{
	char	*tmp;
	void	*pointer;
	char	*to_print;

	tmp = p_itoa(p_get_act_time(phi));
	to_print = p_strjoin(tmp, " ");
	free(tmp);
	tmp = p_itoa(phi->tag);
	pointer = to_print;
	to_print = p_strjoin(to_print, tmp);
	free(pointer);
	free(tmp);
	pointer = to_print;
	to_print = p_strjoin(to_print, action);
	free(pointer);
	pointer = to_print;
	if (color == 1)
		to_print = p_strjoin(KRED, to_print);
	else
		to_print = p_strjoin(KNRM, to_print);
	free(pointer);
	pthread_mutex_lock(phi->sys->m_write);
	if (*phi->sys->b_dead == false)
		write(1, to_print, p_str_len(to_print));
	pthread_mutex_unlock(phi->sys->m_write);
	free(to_print);
}
