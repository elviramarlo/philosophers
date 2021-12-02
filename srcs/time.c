/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:06:26 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/02 20:49:30 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	present_time(int time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000 + start.tv_usec / 1000 - time);
}

//printf("FILOSOFO NUMERO: %d\n", l->philo.num_philo);
//printf("QUE TIEMPO HA PASADO Y HA MUERTO: %u\n", present_time(0) 
//- l->philo.the_last_supper);

int	philo_died(t_philolist *l)
{
	int	i;

	i = 0;
	while (i < l->philo.num_total_philo)
	{
		if (!l->philo.is_eating)
		{
			if (l->philo.the_last_supper)
			{
				if ((present_time(0) - l->philo.the_last_supper)
					> l->philo.time_die)
				{
					print_state(l, 'd');
					l->philo.philo_has_died = 1;
				}
			}
			else
			{
				if ((present_time(l->philo.time) - l->philo.the_last_supper)
					> l->philo.time_die)
				{
					print_state(l, 'd');
					l->philo.philo_has_died = 1;
				}
			}
		}
		if (l->philo.philo_has_died || (l->philo.check_num_eat
				&& !l->philo.num_must_eat))
			return (1);
		l = l->next;
		i++;
	}
	return (0);
}

/* void	ft_usleep(int time_of_action)
{
	int	start;

	start = present_time(0);
	while ((present_time(0) - start) < time_of_action)
		usleep(100);
} */