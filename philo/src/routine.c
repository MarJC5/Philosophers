/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:50:30 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/31 21:23:01 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	routine_fork(t_philo *philo)
{
	if (!am_i_starved(philo))
	{
		print_event("is \033[1;33mthinking\033[0m",
			philo->position, now(philo));
		pthread_mutex_lock(&philo->fork);
		print_event("has taken a \033[1;37mfork\033[0m",
			philo->position, now(philo));
		if (philo->status->num_of_philo == 1)
		{
			oh_wait(philo, philo->status->time_to_eat);
			print_event("is \033[1;31mdead\033[0m",
				philo->position, now(philo));
			{
				philo->is_dead += 1;
				return (EXIT_FAILURE);
			}
		}
		is_your_fork_free(philo);
	}
	return (EXIT_SUCCESS);
}

void	routine_sleep(t_philo *philo)
{
	if (!am_i_starved(philo) && philo->is_dead != 1)
	{
		print_event("is \033[1;36msleeping\033[0m",
			philo->position, now(philo));
		oh_wait(philo, philo->status->time_to_sleep);
		am_i_full(philo);
	}
}

void	routine_eat(t_philo *philo)
{
	if (!am_i_starved(philo) && !routine_fork(philo))
	{
		philo->last_meal = now(philo);
		philo->eat_count += 1;
		print_event("is \033[1;32meating\033[0m", philo->position,
			philo->last_meal);
		oh_wait(philo, philo->status->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
	}
}
