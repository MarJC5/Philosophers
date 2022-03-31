/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:50:30 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/31 07:49:55 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	routine_fork(t_philo *philo)
{
	print_event("has taken a fork", philo->position, now(philo));
}

void	routine_eat(t_philo *philo)
{
	philo->last_meal = now(philo);
	print_event("is eating", philo->position,
		philo->last_meal);
}

void	routine_sleep(t_philo *philo)
{
	print_event("is sleeping", philo->position, now(philo));
}

void	routine_think(t_philo *philo)
{
	print_event("is thinking", philo->position, now(philo));
}

void	routine_dead(t_philo *philo)
{
	print_event("is dead", philo->position, now(philo));
}
