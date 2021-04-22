/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:35:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/22 16:05:57 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*live(t_phi *phi)
{
	pthread_t		monitor;

	sem_wait(phi->sys->s_l_m_t);
	if (phi->l_m_t == 0L)
	{
		pthread_create(&monitor, NULL, p_monitor_vitals, (void*)phi);
		phi->l_m_t = p_get_act_time(phi->sys->s_t);
	}
	sem_post(phi->sys->s_l_m_t);
	p_think(phi);
	p_eat(phi);
	p_sleep(phi);
	if (phi->sys->b_dead == false && phi->sys->args.must_eat != 0)
		return (live(phi));
	else
		while (1)
			;
	return (NULL);
}

static void	*p_each_philo_are_sated(void *arg)
{
	unsigned int	i;
	t_phi			*phi;

	i = 0;
	phi = (t_phi*)arg;
	while (i < phi->sys->args.phi_nb)
	{
		sem_wait(phi->sys->s_goal);
		i++;
	}
	if (phi->sys->b_dead == true)
		return (NULL);
	sem_wait(phi->sys->s_write);
	printf(KGRN"%ld Everyone sat\n", p_get_act_time(phi->sys->s_t));
	sem_post(phi->sys->s_death);
	return (NULL);
}

static void	*p_butcher(void *arg)
{
	unsigned int	i;
	t_phi			*phi;

	i = 0;
	phi = (t_phi*)arg;
	sem_wait(phi->sys->s_death);
	phi->sys->b_dead = true;
	while (i < phi->sys->args.phi_nb)
	{
		sem_post(phi->sys->s_goal);
		i++;
	}
	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		kill(phi[i].pid, SIGKILL);
		i++;
	}
	return (NULL);
}

static void	start_simulation(t_phi *phi
						, pthread_t *death_catcher, pthread_t *goal_monitor)
{
	unsigned int	i;
	t_bool			even;

	i = 0;
	even = false;
	pthread_create(death_catcher, NULL, p_butcher, (void*)phi);
	pthread_create(goal_monitor, NULL, p_each_philo_are_sated, (void*)phi);
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].pid = fork();
		if (phi[i].pid == -1)
			clean_exit(phi, EXIT_FAILURE);
		if (phi[i].pid == 0)
			live(&phi[i]);
		usleep(50);
		i += 2;
		if (i >= phi->sys->args.phi_nb && even == false)
		{
			even = true;
			i = 1;
		}
	}
}

int			main(int ac, char *av[])
{
	t_sys			system;
	t_phi			*philosophers;
	pthread_t		death_catcher;
	pthread_t		goal_monitor;

	memset(&system, 0, sizeof(t_sys));
	philosophers = NULL;
	if (load_program(ac, av, &system, &philosophers) == EXIT_FAILURE)
		clean_exit(philosophers, EXIT_FAILURE);
	start_simulation(philosophers, &death_catcher, &goal_monitor);
	pthread_join(death_catcher, NULL);
	pthread_join(goal_monitor, NULL);
	clean_exit(philosophers, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
