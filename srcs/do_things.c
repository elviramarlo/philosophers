/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_things.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:10 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/02 21:20:40 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	sleep_and_think(t_philolist *list)
{
	print_state(list, 's');
	usleep(list->philo.time_sleep * 1000);
	if (check_dead(list))
		return (0);
	print_state(list, 't');
	eat(list);
	return (0);
}

static void	take_forks(t_philolist *list)
{
	list->philo.fork = 1;
	print_state(list, 'f');
	list->prev->philo.fork = 1;
	print_state(list, 'f');
}


int	eat(t_philolist *list)
{
	while (!list->philo.is_his_turn)
	{
	}
	if (check_dead(list))
		return (0);
	if (list->philo.is_his_turn)
	{
		pthread_mutex_lock(&list->philo.mutex_fork);
		pthread_mutex_lock(&list->prev->philo.mutex_fork);
		take_forks(list);
		list->philo.is_eating = 1;
		print_state(list, 'e');
		usleep(list->philo.time_eat * 1000);
		list->philo.is_his_turn = 0;
		list->next->philo.is_his_turn = 1;
		list->prev->philo.is_his_turn = 1;
		pthread_mutex_unlock(&list->philo.mutex_fork);
		pthread_mutex_unlock(&list->prev->philo.mutex_fork);
		list->philo.the_last_supper = present_time(0);
		list->philo.is_eating = 0;
		if (list->philo.check_num_eat)
			list->philo.num_must_eat--;
	}
	if ((!list->philo.check_num_eat || list->philo.num_must_eat)
		&& !list->philo.philo_has_died && !check_dead(list))
		sleep_and_think(list);
	return (0);
}
