/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:24:05 by jmartin           #+#    #+#             */
/*   Updated: 2022/04/04 15:06:03 by jmartin          ###   ########.fr       */
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
	struct s_philo	*r_fork;
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
void	oh_wait(t_philo *philo, int time_ref);

/**
 * MESSAGE
 */

void	print_event(t_philo *philo, char *str, int philo_num, long timestamp);

/**
 * INIT
 */

int		is_args_valid(t_status *status);
void	init_status(t_status *status, char **args);
void	init_philo_thread(t_status *status);

/**
 * CLEAN STUFF
 */

void	clean_stuff(t_status *status);

/**
 * Routine
 */

int		am_i_full(t_philo *philo);
int		am_i_starved(t_philo *philo);
int		routine_fork(t_philo *philo);
void	routine_eat(t_philo *philo);
void	routine_sleep(t_philo *philo);

#endif
