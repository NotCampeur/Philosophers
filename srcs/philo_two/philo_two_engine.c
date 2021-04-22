/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_engine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:35:07 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 23:35:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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

static t_bool			init_philosophers(t_sys *system)
{
	pthread_t		*phil;

	phil = (pthread_t *)malloc(sizeof(pthread_t) * (system->args.phi_nb));
	if (phil == NULL)
		return (false);
	memset(phil, 0, sizeof(*phil));
	system->phi = phil;
	return (true);
}

static t_bool			init_semaphores(t_sys *system)
{
	sem_unlink("fork");
	system->s_fork = sem_open("fork", O_CREAT, 0777, system->nb_fork);
	sem_unlink("write");
	system->s_write = sem_open("write", O_CREAT, 0777, 1);
	return (true);
}

int						load_program(int ac, char *av[]
										, t_sys *system, t_phi **phi)
{
	unsigned int	i;

	i = 0;
	if (parse_args(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	system->args = get_args(ac, av);
	*phi = (t_phi*)malloc(sizeof(t_phi) * system->args.phi_nb);
	if (phi == NULL)
		return (EXIT_FAILURE);
	memset(*phi, 0, sizeof(t_phi) * system->args.phi_nb);
	system->nb_fork = (system->args.phi_nb == 1) ? 2 : system->args.phi_nb;
	if (init_philosophers(system) == false || init_semaphores(system) == false)
		return (EXIT_FAILURE);
	gettimeofday(&system->s_t, NULL);
	while (i < system->args.phi_nb)
	{
		(*phi)[i].sys = (t_sys*)malloc(sizeof(t_sys));
		*(*phi)[i].sys = *system;
		(*phi)[i].tag = i + 1;
		i++;
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
		sem_close(phi->sys->s_fork);
		sem_close(phi->sys->s_write);
		p_clean_free((void**)&phi[i].sys->phi);
		while (i < phi_nb)
		{
			p_clean_free((void**)&phi[i].sys);
			i++;
		}
	}
	p_clean_free((void**)&phi);
	return (ret);
}
