/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:24:05 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/28 13:10:42 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ARGS_ERR "number_of_philosophers time_to_die time_to_eat time_to_sleep\
	[number_of_times_each_philosopher_must_eat]"

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct t_philo
{
	int		position;
	int		left_fork;
	int		right_fork;
	int		eat_count;
	int		is_eating;
	long	last_meal;
}	t_philo;

typedef struct s_status
{
	long	time_start;
	int		number_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_to_eat;
	t_philo	**philo;
}	t_status;

/**
 * MINI LIBFT
 */

int		ft_atoi(const char *str);

/**
 * TIME
 */

long	current_timestamp(void);

/**
 * MESSAGE
 */

void	print_event(char *str, int philo_num, long timestamp);

/**
 * INIT
 */

void	init_philo(t_status *status);
void	init_status(t_status *status, char **args);

/**
 * CLEAN STUFF
 */

void	clean_stuff(t_status *status);

#endif
