/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:04:34 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/30 08:08:35 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	init_fork(t_status *status)
{
	int	i;

	i = -1;
	while (++i < status->num_of_philo)
	{
		if (i + 1 == status->num_of_philo)
			status->philo[i]->r_fork = status->philo[0];
		else
			status->philo[i]->r_fork = status->philo[i + 1];
		if (i == 0)
			status->philo[i]->l_fork = status->philo[status->num_of_philo - 1];
		else
			status->philo[i]->l_fork = status->philo[i - 1];
	}
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
		philo->is_eating = 0;
		philo->last_meal = 0;
		philo->eat_count = 0;
		philo->status = status;
		status->philo[i] = philo;
	}
	init_fork(status);
}

void	init_status(t_status *status, char **args)
{
	status->num_of_philo = ft_atoi(args[1]);
	status->time_to_die = ft_atoi(args[2]);
	status->time_to_eat = ft_atoi(args[3]);
	status->time_to_sleep = ft_atoi(args[4]);
	if (args[5] != NULL)
		status->num_of_times_to_eat = ft_atoi(args[5]);
	else
		status->num_of_times_to_eat = -1;
	status->philo = malloc(status->num_of_philo * sizeof(t_philo));
	if (!status->philo)
		return ;
	init_philo(status);
}

void	*hello_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_event("is alive", philo->position,
		current_timestamp() - philo->status->time_start);
	return (NULL);
}

void	init_philo_thread(t_status *status, pthread_t *thread_id)
{
	int	i;

	i = -1;
	thread_id = (pthread_t *)malloc(status->num_of_philo * sizeof(pthread_t));
	status->time_start = current_timestamp();
	while (++i < status->num_of_philo)
		pthread_create(&thread_id[i], NULL, hello_philo, status->philo[i]);
	i = -1;
	while (++i < status->num_of_philo)
		pthread_join(thread_id[i], NULL);
}
