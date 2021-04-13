/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_part_tools.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:25 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 12:02:55 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_PART_TOOLS_H
# define COMMON_PART_TOOLS_H

/*
** Count the number of decimals in a number
*/
int	nbr_len(long long int nbr);

/*
** Will count the numbers of characters from char *str.
*/
int	str_len(char *str);

/*
** Convert a char * to int
*/
int	p_atoi(char *str);

#endif
