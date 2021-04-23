/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_engine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:35:07 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/23 01:38:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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

static t_bool			init_semaphores(t_sys *system)
{
	sem_unlink("fork");
	system->s_fork = sem_open("fork", O_CREAT, 777, system->nb_fork);
	sem_unlink("write");
	system->s_write = sem_open("write", O_CREAT, 777, 1);
	sem_unlink("goal");
	system->s_goal = sem_open("goal", O_CREAT, 777, 0);
	sem_unlink("death");
	system->s_death = sem_open("death", O_CREAT, 777, 0);
	sem_unlink("l_m_t");
	system->s_l_m_t = sem_open("l_m_t", O_CREAT, 777, 1);
	if (system->s_fork == SEM_FAILED || system->s_write == SEM_FAILED
		|| system->s_goal == SEM_FAILED || system->s_death == SEM_FAILED
		|| system->s_l_m_t == SEM_FAILED)
		return (false);
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
	if (init_semaphores(system) == false)
		return (EXIT_FAILURE);
	gettimeofday(&system->s_t, NULL);
	system->b_dead = false;
	while (i < system->args.phi_nb)
	{
		(*phi)[i].sys = (t_sys*)malloc(sizeof(t_sys));
		*(*phi)[i].sys = *system;
		(*phi)[i].tag = i + 1;
		i++;
	}
	return (EXIT_SUCCESS);
}

void					clean_exit(t_phi *phi, int ret)
{
	unsigned int	i;
	unsigned int	phi_nb;

	i = 0;
	if (phi != NULL)
	{
		phi_nb = phi->sys->args.phi_nb;
		sem_close(phi->sys->s_fork);
		sem_close(phi->sys->s_write);
		sem_close(phi->sys->s_l_m_t);
		sem_close(phi->sys->s_goal);
		sem_close(phi->sys->s_death);
		while (i < phi_nb)
		{
			p_clean_free((void**)&phi[i].sys);
			i++;
		}
	}
	p_clean_free((void**)&phi);
	exit(ret);
}
