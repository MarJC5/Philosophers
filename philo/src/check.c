/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:38:53 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/04 11:54:40 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	am_i_starved(t_philo *philo)
{
	if (now(philo) - philo->last_meal >= philo->status->time_to_die)
	{
		pthread_mutex_lock(&philo->status->print);
		print_event(philo, "is \033[1;31mdead\033[0m",
			philo->position, now(philo));
		pthread_mutex_unlock(&philo->status->print);
		philo->is_dead += 1;
		philo->status->state += 1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	am_i_full(t_philo *philo)
{
	if (philo->eat_count >= philo->status->num_of_times_to_eat
		&& philo->status->num_of_times_to_eat != -1)
	{
		philo->is_full = 1;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	is_your_fork_free(t_philo *philo)
{
	if (!am_i_starved(philo->l_fork) && !am_i_starved(philo) && !philo->is_dead)
	{
		pthread_mutex_lock(&philo->l_fork->fork);
		print_event(philo, "has taken a \033[1;37mfork\033[0m",
			philo->position, now(philo));
	}
	else
		routine_fork(philo);
}
