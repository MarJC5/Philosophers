/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:50:30 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/04 11:55:37 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	routine_fork(t_philo *philo)
{
	if (!am_i_starved(philo) && philo->status->state < 1)
	{
		pthread_mutex_lock(&philo->fork);
		print_event(philo, "has taken a \033[1;37mfork\033[0m",
			philo->position, now(philo));
		if (philo->status->num_of_philo == 1)
		{
			oh_wait(philo, philo->status->time_to_die);
			print_event(philo, "is \033[1;31mdead\033[0m",
				philo->position, now(philo));
			philo->is_dead += 1;
			philo->status->state += 1;
			return (EXIT_FAILURE);
		}
		is_your_fork_free(philo);
	}
	return (EXIT_SUCCESS);
}

void	routine_sleep(t_philo *philo)
{
	if (!am_i_starved(philo) && philo->is_dead != 1
		&& philo->status->state < 1)
	{
		print_event(philo, "is \033[1;36msleeping\033[0m",
			philo->position, now(philo));
		am_i_full(philo);
		oh_wait(philo, philo->status->time_to_sleep);
		print_event(philo, "is \033[1;33mthinking\033[0m",
			philo->position, now(philo));
	}
}

void	routine_eat(t_philo *philo)
{
	if (!am_i_starved(philo) && !routine_fork(philo)
		&& philo->status->state < 1)
	{
		philo->last_meal = now(philo);
		philo->eat_count += 1;
		if (philo->eat_count == philo->status->num_of_times_to_eat)
			philo->status->all_eaten += 1;
		if (philo->status->num_of_times_to_eat > 0)
			printf("%10ld ms \033[1;37m%3d\033[0m is \033[1;32meating\033[0m #%d\n",
				philo->last_meal, philo->position, philo->eat_count);
		else
			print_event(philo, "is \033[1;32meating\033[0m", philo->position,
				philo->last_meal);
		oh_wait(philo, philo->status->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
	}
}
