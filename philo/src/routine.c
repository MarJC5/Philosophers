/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:50:30 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/05 13:38:33 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	le_forchette_sono_disponibili(t_philo *philo)
{
	if (philo->status->state < 1)
	{
		pthread_mutex_lock(&philo->fork);
		print_event(philo, "has taken a \033[1;37mfork\033[0m",
			philo->position, now(philo));
		if (philo->status->num_of_philo == 1)
		{
			oh_aspetta_calmati(philo, philo->status->time_to_die);
			print_event(philo, "is \033[1;31mdied\033[0m",
				philo->position, now(philo));
			philo->is_dead += 1;
			philo->status->state += 1;
			pthread_mutex_unlock(&philo->fork);
		}
		pthread_mutex_lock(&philo->l_fork->fork);
		print_event(philo, "has taken a \033[1;37mfork\033[0m",
			philo->position, now(philo));
	}
}

void	mangia_bene(t_philo *philo)
{
	le_forchette_sono_disponibili(philo);
	if (philo->status->state < 1)
	{
		philo->last_meal = now(philo);
		print_event(philo, "is \033[1;32meating\033[0m",
			philo->position, philo->last_meal);
		oh_aspetta_calmati(philo, philo->status->time_to_eat);
		philo->eat_count += 1;
		if (philo->eat_count == philo->status->num_of_times_to_eat)
		{
			philo->status->all_eaten += 1;
			philo->status->state += 1;
		}
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->l_fork->fork);
	if (philo->status->state < 1)
	{
		print_event(philo, "is \033[1;36msleeping\033[0m",
			philo->position, now(philo));
		oh_aspetta_calmati(philo, philo->status->time_to_sleep);
		print_event(philo, "is \033[1;33mthinking\033[0m",
			philo->position, now(philo));
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->position % 2 == 0)
		usleep(1000);
	while (philo->status->state < 1)
	{
		if (philo->status->all_eaten == philo->status->num_of_philo)
			break ;
		mangia_bene(philo);
		am_i_starved(philo);
		am_i_full(philo);
	}
	return (NULL);
}
