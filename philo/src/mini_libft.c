/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:55:45 by jmartin           #+#    #+#             */
/*   Updated: 2022/03/28 12:01:47 by jmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		count;
	int		num;

	sign = 1;
	count = 0;
	num = 0;
	while (str[count] == ' '
		|| str[count] == '\f'
		|| str[count] == '\n'
		|| str[count] == '\r'
		|| str[count] == '\t'
		|| str[count] == '\v')
		count++;
	if (str[count] == '-')
		sign = -1;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (str[count] && ft_isdigit(str[count]))
		num = num * 10 + (str[count++] - '0');
	return (sign * num);
}
