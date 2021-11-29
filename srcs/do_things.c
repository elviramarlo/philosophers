/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_things.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:10 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/29 23:46:12 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	sleep_and_think(t_philolist *list)
{
	print_state(list, 's');
	usleep(list->philo.time_sleep * 1000);
	print_state(list, 't');
	eat(list);
}

static void	take_forks(t_philolist *list)
{
	list->philo.fork = 1;
	print_state(list, 'f');
	list->prev->philo.fork = 1;
	print_state(list, 'f');
}

void	eat(t_philolist *list)
{
	while (!list->philo.is_his_turn)
	{
	}
	if (list->philo.is_his_turn)
	{
		pthread_mutex_lock(&list->philo.mutex_fork);
		pthread_mutex_lock(&list->prev->philo.mutex_fork);
		take_forks(list);
		print_state(list, 'e');
		usleep(list->philo.time_eat * 1000);
		list->philo.is_his_turn = 0;
		list->next->philo.is_his_turn = 1;
		list->prev->philo.is_his_turn = 1;
		pthread_mutex_unlock(&list->philo.mutex_fork);
		pthread_mutex_unlock(&list->prev->philo.mutex_fork);
		if (list->philo.check_num_eat)
			list->philo.num_must_eat--;
	}
	if (!list->philo.check_num_eat || list->philo.num_must_eat)
		sleep_and_think(list);
}
