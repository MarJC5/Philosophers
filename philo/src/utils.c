/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:55:45 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/03 21:30:12 by jmartin          ###   ########.fr       */
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

void	oh_wait(t_philo *philo, int time_ref)
{
	long	ms;

	ms = now(philo);
	while (!am_i_starved(philo))
	{
		if (now(philo) - ms >= time_ref)
			break ;
		usleep(100);
	}
}

void	print_event(char *str, int philo_num, long timestamp)
{
	printf("%ld \033[1;37m%d\033[0m %s\n", timestamp, philo_num, str);
}

void	clean_stuff(t_status *status)
{
	while (status->num_of_philo)
		free(status->philo[status->num_of_philo--]);
	free(status->philo);
	free(status);
}
