/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:24:05 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/05 14:19:01 by jmartin          ###   ########.fr       */
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

typedef struct s_philo
{
	int				position;
	int				eat_count;
	int				is_dead;
	int				is_full;
	long			last_meal;
	pthread_mutex_t	fork;
	struct s_philo	*l_fork;
	struct s_status	*status;
}	t_philo;

typedef struct s_status
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_philo;
	int				num_of_times_to_eat;
	int				state;
	int				all_eaten;
	long			time_start;
	pthread_mutex_t	check;
	pthread_mutex_t	print;
	pthread_t		*thread_id;
	t_philo			**philo;
}	t_status;

/**
 * MINI LIBFT
 */

int		ft_atoi(const char *str);

/**
 * TIME
 */

long	current_timestamp(void);
long	now(t_philo *philo);
void	oh_aspetta_calmati(t_philo *philo, int time_ref);

/**
 * MESSAGE
 */

void	print_event(t_philo *philo, char *str, int philo_num, long timestamp);

/**
 * INIT
 */

void	init_status(t_status *status, char **args);

/**
 * CLEAN
 */

void	clean_stuff(t_status *status);

/**
 * ROUTINE
 */

int		am_i_full(t_philo *philo);
int		am_i_starved(t_philo *philo);
void	*routine(void *arg);
void	mangia_bene(t_philo *philo);

#endif
