/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_part_tools.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:39:25 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/20 14:14:48 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_PART_TOOLS_H
# define COMMON_PART_TOOLS_H

/*
** Free an address on the heap and set it to NULL
*/
void	p_clean_free(void **addr);

/*
** Count the number of decimals in a number
*/
int		p_nbr_len(long long int nbr);

/*
** Count the number of char in a char *
*/
size_t	p_str_len(char const *str);

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
**	Will check if every args are correct and will store them
*/
int		parse_args(int ac, char *av[]);

/*
** Print a msg formated like [act_time id action] in color defined by color.
*/
void	p_put_timestamp(long act_time, unsigned int id
											, char const *action, char color);

/*
** get the actual time in ms since the beginning of the program.
*/
long	p_get_act_time(struct timeval	start_time);

/*
** Check if philosopher is done eating.
*/
t_bool	p_check_hunger(int *must_eat);

#endif
