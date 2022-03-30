/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:25:58 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/30 08:03:49 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	pthread_t	*thread_id;
	t_status	*status;

	if (argc < 5)
		printf("\033[0;33mWrong numbers of arguments, please give: \033[0m\n%s\n",
			ARGS_ERR);
	if (argc == 5 || argc == 6)
	{
		status = malloc(sizeof(t_status));
		if (!status)
			return (0);
		thread_id = NULL;
		init_status(status, argv);
		init_philo_thread(status, thread_id);
		clean_stuff(status);
	}
	return (0);
}
