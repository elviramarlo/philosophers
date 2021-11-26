/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:10 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/26 17:16:00 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void think(t_philolist *list)
{
	printf("Philosopher %d is thinking\n", list->philo.num_philo);
	usleep(list->philo.time_think);
	eat(list);
}

void	go_sleep(t_philolist *list)
{
	printf("Philosopher %d is sleeping\n", list->philo.num_philo);
	usleep(list->philo.time_sleep);
	think(list);
}

void	take_left_fork(t_philolist *list)
{

	list->prev->philo.fork = 1;
	printf("Philosopher %d has taken a fork\n", list->philo.num_philo);
}

static void	take_right_fork(t_philolist *list)
{

	list->philo.fork = 1;
	printf("Philosopher %d has taken a fork\n", list->philo.num_philo);
}

void	eat(t_philolist *list)
{
	if (list->philo.is_his_turn)
	{
		take_right_fork(list);
		take_left_fork(list);
		printf("Philosopher %d is eating\n", list->philo.num_philo);
		usleep(list->philo.time_eat);
		list->philo.is_his_turn = 0;
		list->next->philo.is_his_turn = 1;
		list->prev->philo.is_his_turn = 1;
	}
	go_sleep(list);
}