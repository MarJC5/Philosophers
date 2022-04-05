/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:55:45 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/05 14:19:52 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	current_timestamp(void)
{
	struct timeval	tv;
	long			milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (milliseconds);
}

long	now(t_philo *philo)
{
	return (current_timestamp() - philo->status->time_start);
}

void	oh_aspetta_calmati(t_philo *philo, int time_ref)
{
	long	ms;

	ms = now(philo);
	while (!am_i_starved(philo))
	{
		if (now(philo) - ms >= time_ref)
			break ;
		usleep(100);
	}
	am_i_starved(philo);
}

void	print_event(t_philo *philo, char *str, int philo_num, long timestamp)
{
	pthread_mutex_lock(&philo->status->print);
	if (philo->status->state < 1)
		printf("%10ld ms \033[1;37m%3d\033[0m %s\n", timestamp, philo_num, str);
	pthread_mutex_unlock(&philo->status->print);
}

void	clean_stuff(t_status *status)
{
	while (status->num_of_philo)
		free(status->philo[status->num_of_philo--]);
	free(status->philo);
	free(status);
}
