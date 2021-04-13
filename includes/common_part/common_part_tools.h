/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_part_tools.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:25 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 17:51:47 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_PART_TOOLS_H
# define COMMON_PART_TOOLS_H

/*
** Count the number of decimals in a number
*/
int	nbr_len(long long int nbr);

/*
** Count the number of char in a char *
*/
size_t	p_str_len(char const *str);

/*
** Will count the numbers of characters from char *str.
*/
int	str_len(char *str);

/*
** Convert a char * to int
*/
int	p_atoi(char *str);

/*
** Print a number in the standard output
*/
void	p_putnbr(int nb);

/*
** Print a unsigned long long number in the standard output
*/
void	p_putull(unsigned long long nb);

/*
** Print c in the standard output
*/
void	p_putchar(char c);

/*
** Print a timestamp and link an action to an index
*/
void	p_put_timestamp(struct timeval *time, struct timeval *start_time
											, int index, char const *action);

#endif
