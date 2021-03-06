/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:38:53 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/05 13:46:22 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	am_i_starved(t_philo *philo)
{
	pthread_mutex_lock(&philo->status->check);
	if (now(philo) - philo->last_meal >= philo->status->time_to_die)
	{
		print_event(philo, "is \033[1;31mdied\033[0m",
			philo->position, now(philo));
		philo->is_dead += 1;
		philo->status->state += 1;
		pthread_mutex_unlock(&philo->status->check);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&philo->status->check);
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
