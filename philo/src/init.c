/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:04:34 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/05 08:56:32 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	init_fork(t_status *status)
{
	int	i;

	i = -1;
	while (++i < status->num_of_philo)
	{
		if (i == 0)
			status->philo[i]->l_fork = status->philo[status->num_of_philo - 1];
		else
			status->philo[i]->l_fork = status->philo[i - 1];
		pthread_mutex_init(&status->philo[i]->fork, NULL);
	}
	pthread_mutex_init(&status->check, NULL);
}

static void	init_philo(t_status *status)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < status->num_of_philo)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return ;
		philo->position = i + 1;
		philo->last_meal = 0;
		philo->eat_count = 0;
		philo->is_dead = 0;
		philo->is_full = 0;
		philo->status = status;
		status->philo[i] = philo;
	}
	init_fork(status);
}

static void	init_philo_thread(t_status *status)
{
	int	i;

	i = -1;
	status->thread_id = malloc(status->num_of_philo * sizeof(pthread_t));
	if (!status->thread_id)
		return ;
	status->time_start = current_timestamp();
	while (++i < status->num_of_philo)
	{
		if (pthread_create(&status->thread_id[i],
				NULL, routine, status->philo[i]))
		{
			printf("Error while creating new thread.");
			clean_stuff(status);
			return ;
		}
	}
	if (status->thread_id)
	{
		i = -1;
		while (++i < status->num_of_philo)
			pthread_join(status->thread_id[i], NULL);
		free(status->thread_id);
	}
}

void	init_status(t_status *status, char **args)
{
	status->num_of_philo = ft_atoi(args[1]);
	status->time_to_die = ft_atoi(args[2]);
	status->time_to_eat = ft_atoi(args[3]);
	status->time_to_sleep = ft_atoi(args[4]);
	status->state = 0;
	status->all_eaten = 0;
	if (status->num_of_philo > 0 && status->time_to_die >= 0
		&& status->time_to_eat >= 0 && status->time_to_sleep >= 0)
	{
		if (args[5] != NULL)
		{
			status->num_of_times_to_eat = ft_atoi(args[5]);
			if (status->num_of_times_to_eat <= 0)
				return ;
		}
		status->philo = malloc(status->num_of_philo * sizeof(t_philo));
		if (!status->philo)
			return ;
		init_philo(status);
		init_philo_thread(status);
		clean_stuff(status);
	}
	else
		printf("Error invalid arguments values");
}
