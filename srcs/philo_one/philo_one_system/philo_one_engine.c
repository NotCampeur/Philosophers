/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:59:50 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/15 11:46:09 by ldutriez         ###   ########.fr       */
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

static void				init_mutexes(t_sys *system)
{
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	*m_write;
	unsigned int	i;

	m_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
												* (system->nb_fork));
	m_write = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	i = 0;
	if (m_fork == NULL || m_write == NULL)
		return ;
	memset(m_fork, 0, sizeof(pthread_mutex_t) * (system->nb_fork));
	memset(m_write, 0, sizeof(pthread_mutex_t));
	while (i < system->nb_fork)
	{
		pthread_mutex_init(&(m_fork[i]), NULL);
		i++;
	}
	pthread_mutex_init(m_write, NULL);
	system->m_fork = m_fork;
	system->m_write = m_write;
}

int						load_program(int ac, char *av[]
										, t_sys *system, t_phi **phi)
{
	unsigned int	i;

	i = 0;
	memset(&system->args, 0, sizeof(system->args));
	system->m_fork = NULL;
	system->phi = NULL;
	if (parse_args(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	system->args = get_args(ac, av);
	*phi = (t_phi*)malloc(sizeof(t_phi) * system->args.phi_nb);
	system->nb_fork = (system->args.phi_nb == 1) ? 2 : system->args.phi_nb;
	system->phi = init_philosophers(system);
	if (system->phi == NULL)
		return (EXIT_FAILURE);
	init_mutexes(system);
	if (system->m_fork == NULL || system->m_write == NULL)
		return (EXIT_FAILURE);
	gettimeofday(&system->s_t, NULL);
	system->b_dead = (t_bool*)malloc(sizeof(t_bool));
	*system->b_dead = false;
	while (i++ < system->args.phi_nb)
	{
		(*phi)[i - 1].sys = (t_sys*)malloc(sizeof(t_sys));
		*(*phi)[i - 1].sys = *system;
	}
	return (EXIT_SUCCESS);
}

int						clean_exit(t_phi *phi, int ret)
{
	unsigned int	i;
	unsigned int	phi_nb;

	i = 0;
	if (phi != NULL)
	{
		phi_nb = phi->sys->args.phi_nb;
		while (i < phi[0].sys->nb_fork)
		{
			pthread_mutex_destroy(&(phi[0].sys->m_fork[i]));
			i++;
		}
		i = 0;
		p_clean_free((void**)&phi[i].sys->b_dead);
		p_clean_free((void**)&phi[i].sys->m_fork);
		p_clean_free((void**)&phi[i].sys->phi);
		pthread_mutex_destroy(phi[i].sys->m_write);
		p_clean_free((void**)&phi[i].sys->m_write);
		while (i < phi_nb)
		{
			p_clean_free((void**)&phi[i].sys);
			i++;
		}
	}
	p_clean_free((void**)&phi);
	return (ret);
}
