/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_things.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:34:10 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/09 19:43:23 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	sleep_and_think(t_philolist *list)
{
	print_state(list, 's');
	ft_usleep(list->philo->time_sleep);
	if (check_death(list))
		return (0);
	print_state(list, 't');
	eat(list);
	return (0);
}

static void	take_forks(t_philolist *list)
{
	list->philo->fork = 1;
	print_state(list, 'f');
	list->prev->philo->fork = 1;
	print_state(list, 'f');
}

int	eat(t_philolist *list)
{
	while (!list->philo->is_his_turn)
	 	continue ;
	if (list->philo->is_his_turn && !check_death(list))
	{
		pthread_mutex_lock(&list->philo->mutex_fork);
		take_forks(list);
		list->philo->the_last_supper = present_time(0);
		print_state(list, 'e');
		ft_usleep(list->philo->time_eat);
		list->philo->is_his_turn = 0;
		list->next->philo->is_his_turn = 1;
		list->prev->philo->is_his_turn = 1;
		pthread_mutex_unlock(&list->philo->mutex_fork);
		if (list->philo->check_num_eat)
			list->philo->num_must_eat--;
	}
	if ((!list->philo->check_num_eat || list->philo->num_must_eat)
		&& !list->philo->philo_has_died && !check_death(list))
		sleep_and_think(list);
	return (0);
}

void	*make_thread(void *param)
{
	t_philolist	*list;

	list = (t_philolist *)param;
	eat(list);
	return (NULL);
}
