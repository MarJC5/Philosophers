/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:55:45 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/28 15:04:10 by jmartin          ###   ########.fr       */
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

void	print_event(char *str, int philo_num, long timestamp)
{
	printf("%ld %d %s\n", timestamp, philo_num, str);
}

void	clean_stuff(t_status *status)
{
	while (status->num_of_philo)
		free(status->philo[status->num_of_philo--]);
	free(status->philo);
	free(status);
}
