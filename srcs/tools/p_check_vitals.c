/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_vitals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:22:51 by ldutriez          #+#    #+#             */
/*   Updated: 2021/04/15 18:00:35 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_part.h"

t_bool	p_check_hunger(t_phi *phi)
{
	if (phi->sys->args.must_eat > 0)
	{
		phi->sys->args.must_eat--;
		if (phi->sys->args.must_eat == 0)
			return (true);
	}
	return (false);
}

void	*p_death_check(void *arg)
{
	unsigned int	i;
	t_phi			*phi;
	t_bool			done;

	i = 0;
	phi = (t_phi*)arg;
	while (i < phi->sys->args.phi_nb)
	{
		done = true;
		if (phi[i].sys->args.must_eat != 0)
			done = false;
		if (p_get_act_time(&phi[i]) - phi[i].l_m_t >= phi->sys->args.t_to_die)
		{
			p_put_timestamp(&phi[i], " died\n", 1);
			*phi->sys->b_dead = true;
			return (NULL);
		}
		i++;
		if (i >= phi->sys->args.phi_nb)
		{
			if (done == true)
			{
				printf(KGRN"Simulation lasted %ldms\n", p_get_act_time(phi));
				return (NULL);
			}
			i = 0;
		}
	}
	return (NULL);
}
