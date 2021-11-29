/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:06:26 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/29 23:51:27 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


 int	present_time(int time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000 + start.tv_usec / 1000 - time);
}

/* void	ft_usleep(int time_of_action)
{
	int	start;

	start = present_time(0);
	while ((present_time(0) - start) < time_of_action)
		usleep(100);
} */