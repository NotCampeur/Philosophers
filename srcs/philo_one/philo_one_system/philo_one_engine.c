/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:59:50 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 12:40:44 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static t_args			get_args(int ac, char *av[])
{
	t_args	result;
	
	result.phi_nb = p_atoi(av[1]);
	result.t_to_die = p_atoi(av[2]);
	result.t_to_eat = p_atoi(av[3]);
	result.t_to_sleep = p_atoi(av[4]);
	result.must_eat = (ac == 6) ? p_atoi(av[5]) : -1;
	return (result);
}

static t_phi		*init_philosophers(t_sys *system)
{
	t_phi			*res;
	unsigned int	i;

	res = (t_phi *)malloc(sizeof(t_phi) * (system->args.phi_nb + 1));
	i = 0;
	if (res == NULL)
		return (NULL);
	memset(res, 0, sizeof(*res));
	while (i < system->args.phi_nb)
	{
		res[i].tag = i;
		i++;
	}
	return (res);
}

static pthread_mutex_t	*init_mutexes(t_sys *system)
{
	pthread_mutex_t	*res;
	unsigned int	i;

	res = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
												* (system->args.phi_nb + 1));
	i = 0;
	if (res == NULL)
		return (NULL);
	memset(res, 0, sizeof(*res));
	while (i < system->args.phi_nb)
	{
		pthread_mutex_init(&(res[i]), NULL);
		i++;
	}
	return (res);
}

int						load_program(int ac, char *av[], t_sys *system)
{
	memset(&system->args, 0, sizeof(system->args));
	system->fork = NULL;
	system->phi = NULL;
	if (parse_args(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	system->args = get_args(ac, av);
	system->phi = init_philosophers(system);
	if (system->phi == NULL)
		return (EXIT_FAILURE);
	system->fork = init_mutexes(system);
	if (system->fork == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int						clean_exit(t_sys *system, int ret)
{
	unsigned int	i;

	i = 0;
	while (i < system->args.phi_nb)
	{
		pthread_mutex_destroy(&(system->fork[i]));
		i++;
	}
	free(system->fork);
	free(system->phi);
	return (ret);
}
