/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_things.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:10 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/17 16:43:11 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	take_forks(t_philolist *list)
{
	pthread_mutex_lock(&list->philo->mutex_fork);
	if (!list->philo->fork)
	{
		list->philo->fork = list->philo->num_philo;
		print_state(list, 'f');
	}
	pthread_mutex_lock(&list->next->philo->mutex_fork);
	if (!list->next->philo->fork)
	{
		list->next->philo->fork = list->philo->num_philo;
		print_state(list, 'f');
	}
	pthread_mutex_unlock(&list->philo->mutex_fork);
	pthread_mutex_unlock(&list->next->philo->mutex_fork);
}

int	eat(t_philolist *list)
{
	while (!list->philo->is_his_turn)
		usleep(100);
	if (list->philo->num_total_philo > 1)
	{
		while ((list->philo->fork != list->philo->num_philo
				|| list->next->philo->fork != list->philo->num_philo))
			take_forks(list);
		if (list->philo->check_num_eat)
			list->philo->num_must_eat--;
		print_state(list, 'e');
		list->philo->the_last_supper = present_time(0);
		ft_usleep(list->philo->time_eat);
		list->philo->is_his_turn = 0;
		list->next->philo->is_his_turn = 1;
		list->prev->philo->is_his_turn = 1;
		list->philo->fork = 0;
		list->next->philo->fork = 0;
	}
	return (0);
}

void	*make_thread(void *param)
{
	t_philolist	*list;

	list = (t_philolist *)param;
	if (list->philo->num_total_philo < 2)
		print_state(list, 'f');
	else
	{
		while (!check_death(list))
		{
			eat(list);
			print_state(list, 's');
			ft_usleep(list->philo->time_sleep);
			print_state(list, 't');
		}
	}
	return (NULL);
}
