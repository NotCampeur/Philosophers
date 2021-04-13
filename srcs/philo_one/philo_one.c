/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 08:57:06 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/13 18:15:34 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		*live(void *arg)
{
	t_phi			*phi;
	struct timeval	act_time;
	struct timeval	prev_time;
	t_bool			sim_end;
	int				count;

	phi = (t_phi*)arg;
	gettimeofday(&act_time, NULL);
	prev_time = act_time;
	sim_end = false;
	count = phi->sys->args.must_eat;
	while (get_elapsed_time(&act_time, prev_time) < phi->sys->args.t_to_die
															&& sim_end == false)
	{
		p_put_timestamp(&act_time, &phi->sys->s_t, phi->tag, " has taken a fork\n");
		p_put_timestamp(&act_time, &phi->sys->s_t, phi->tag, " is eating\n");
		p_eat(act_time, &prev_time);
		p_put_timestamp(&act_time, &phi->sys->s_t, phi->tag, " is sleeping\n");
		p_sleep();
		p_put_timestamp(&act_time, &phi->sys->s_t, phi->tag, " is thinking\n");
		p_think();
		if (count > 0)
		{
			count--;
			if (count == 0)
				sim_end = true;
		}
	}
	if (sim_end == true)
		write(1, "Simulation ended whitout dying\n", 32);
	else
		p_put_timestamp(&act_time, &phi->sys->s_t, phi->tag, " died\n");
	return (NULL);
}

static void	test_thread(t_phi *phi)
{
	unsigned int	i;

	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		phi[i].tag = i;
		pthread_create(&(phi->sys->phi[i]), NULL, &live, (void*)phi);
		i++;
	}
	i = 0;
	while (i < phi->sys->args.phi_nb)
	{
		pthread_join(phi->sys->phi[i], NULL);
		i++;
	}
}

int			main(int ac, char *av[])
{
	t_sys	system;
	t_phi	*philosophers;
	
	philosophers = NULL;
	if (load_program(ac, av, &system, philosophers) == EXIT_FAILURE)
		return (clean_exit(philosophers, EXIT_FAILURE));
	test_thread(philosophers);
	clean_exit(philosophers, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
