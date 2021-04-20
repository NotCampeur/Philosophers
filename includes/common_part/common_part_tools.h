/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_part_tools.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:25 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 10:17:14 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_PART_TOOLS_H
# define COMMON_PART_TOOLS_H

# include "philo_one_struct.h"

/*
** Free an address on the heap and set it to NULL
*/
void	p_clean_free(void **addr);

/*
** Count the number of decimals in a number
*/
int		nbr_len(long long int nbr);

/*
** Count the number of char in a char *
*/
size_t	p_str_len(char const *str);

/*
** Will count the numbers of characters from char *str.
*/
int		str_len(char *str);

/*
** Convert a char * to int
*/
int		p_atoi(char *str);

/*
** Print a number in the standard output
*/
void	p_putnbr(int nb);

/*
** Print a unsigned long long number in the standard output
*/
void	p_putl(long nb);

/*
** Print c in the standard output
*/
void	p_putchar(char c);

/*
** Print a timestamp and link an action to an index
*/
void	p_put_timestamp(t_phi *phi, char const *action, char color);

/*
** get the actual time in ms since the beginning of the program.
*/
long	p_get_act_time(t_phi *phi);

/*
** sleep until the target time or philosopher running time is reach.
*/
void	p_delay(t_phi *phi, long target_time);

/*
** Check if philosopher is done eating.
*/
t_bool	p_check_hunger(t_phi *phi);

/*
** Check if philosophers are dead or if they are done eating.
*/
void	*p_monitor_vitals(void *arg);

#endif
