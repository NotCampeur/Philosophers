/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:35:05 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/21 23:35:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*live(t_phi *phi)
{
	sem_wait(phi->sys->s_l_m_t);
	if (phi->l_m_t == 0L)
		phi->l_m_t = p_get_act_time(phi->sys->s_t);
	sem_post(phi->sys->s_l_m_t);
	p_think(phi);
	p_eat(phi);
	p_sleep(phi);
	if (phi->sys->b_dead == false && phi->sys->args.must_eat != 0)
		return (live(phi));
	else if (phi->sys->b_dead == true)
		exit(EXIT_FAILURE);
	else if (phi->sys->args.must_eat == 0)
		exit(EXIT_SUCCESS);
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
	sem_wait(phi->sys->s_write);
	printf(KGRN"%ld Everyone sat\n", p_get_act_time(phi->sys->s_t));
	sem_post(phi->sys->s_write);
	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		kill(phi[i].pid, SIGKILL);
		i++;
	}
	clean_exit(phi, EXIT_SUCCESS);
	return (NULL);
}

static void	*p_butcher(void *arg)
{
	unsigned int	i;
	t_phi			*phi;

	i = 0;
	phi = (t_phi*)arg;
	sem_wait(phi->sys->s_death);
	while (i < phi->sys->args.phi_nb)
	{
		kill(phi[i].pid, SIGKILL);
		i++;
	}
	clean_exit(phi, EXIT_FAILURE);
	return (NULL);
}

static void	start_simulation(t_phi *phi)
{
	unsigned int	i;
	pthread_t		monitor;
	pthread_t		monitor_global;
	pthread_t		death_catcher;

	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].pid = fork();
		if (phi[i].pid == -1)
			clean_exit(phi, EXIT_FAILURE);
		if (phi[i].pid == 0)
		{
			phi[i].tag = i;
			pthread_create(&monitor, NULL, p_monitor_vitals, (void*)&phi[i]);
			live(&phi[i]);
		}
		usleep(50);
		i += 2;
	}
	i = 1;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].pid = fork();
		if (phi[i].pid == -1)
			clean_exit(phi, EXIT_FAILURE);
		if (phi[i].pid == 0)
		{
			phi[i].tag = i;
			pthread_create(&monitor, NULL, p_monitor_vitals, (void*)&phi[i]);
			live(&phi[i]);
		}
		usleep(50);
		i += 2;
	}
	pthread_create(&death_catcher, NULL, p_butcher, (void*)phi);
	pthread_create(&monitor_global, NULL, p_each_philo_are_sated, (void*)phi);
}

int	main(int ac, char *av[])
{
	t_sys			system;
	t_phi			*philosophers;
	unsigned int	i;
//	pid_t			ret;
	
	i = 0;
	memset(&system, 0, sizeof(t_sys));
	philosophers = NULL;
	if (load_program(ac, av, &system, &philosophers) == EXIT_FAILURE)
		clean_exit(philosophers, EXIT_FAILURE);
	start_simulation(philosophers);
	while (i < philosophers->sys->args.phi_nb)
	{
		waitpid(-1, NULL, 0);
		//if (ret != philosophers[i].pid)
		//	kill(philosophers[i].pid, SIGKILL);
		i++;
	}
	clean_exit(philosophers, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
