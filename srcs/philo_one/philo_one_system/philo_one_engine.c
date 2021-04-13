/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:59:50 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 18:13:35 by ldutriez         ###   ########.fr       */
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

static pthread_t		*init_philosophers(t_sys *system)
{
	pthread_t		*res;

	res = (pthread_t *)malloc(sizeof(pthread_t) * (system->args.phi_nb));
	if (res == NULL)
		return (NULL);
	memset(res, 0, sizeof(*res));
	return (res);
}

static pthread_mutex_t	*init_mutexes(t_sys *system)
{
	pthread_mutex_t	*res;
	unsigned int	i;

	res = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
												* (system->nb_fork));
	i = 0;
	if (res == NULL)
		return (NULL);
	memset(res, 0, sizeof(*res));
	while (i < system->nb_fork)
	{
		pthread_mutex_init(&(res[i]), NULL);
		i++;
	}
	return (res);
}

int						load_program(int ac, char *av[]
										, t_sys *system, t_phi *phi)
{
	unsigned int	i;

	i = 0;
	memset(&system->args, 0, sizeof(system->args));
	system->m_fork = NULL;
	system->phi = NULL;
	if (parse_args(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	system->args = get_args(ac, av);
	phi = (t_phi*)malloc(sizeof(t_phi) * system->args.phi_nb);
	while (i < system->args.phi_nb)
	{
		phi[i].sys = system;
		i++;
	}
	system->nb_fork = (system->args.phi_nb == 1) ? 2 : system->args.phi_nb;
	system->phi = init_philosophers(system);
	if (system->phi == NULL)
		return (EXIT_FAILURE);
	system->m_fork = init_mutexes(system);
	if (system->m_fork == NULL)
		return (EXIT_FAILURE);
	pthread_mutex_init(&system->m_write, NULL);
	gettimeofday(&system->s_t, NULL);
	return (EXIT_SUCCESS);
}

int						clean_exit(t_phi *phi, int ret)
{
	unsigned int	i;

	i = 0;
	if (phi != NULL)
	{
		while (i < phi->sys->args.phi_nb)
		{
			pthread_mutex_destroy(&(phi->sys->m_fork[i]));
			i++;
		}
		pthread_mutex_destroy(&phi->sys->m_write);
		free(phi->sys->m_fork);
		free(phi->sys->phi);
	}
	free(phi);
	return (ret);
}
