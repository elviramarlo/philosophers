/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:01:11 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/12 21:08:40 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static t_philolist	*make_philo(int i, int argc, char **argv)
{
	t_philolist	*list;
	
	list = (t_philolist *)malloc(sizeof(t_philolist));
	list->philo = (t_philo *)malloc(sizeof(t_philo));
	ft_bzero(list->philo, sizeof(t_philo));
	list->philo->num_total_philo = ft_atoi(argv[1]);
	list->philo->time_die = ft_atoi(argv[2]);
	list->philo->time_eat = ft_atoi(argv[3]);
	list->philo->time_sleep = ft_atoi(argv[4]);
	list->philo->num_philo = i;
	pthread_mutex_init(&(list->philo->mutex_fork), NULL);
	list->philo->time = present_time(0);
	if (argc == 6)
	{
		list->philo->num_must_eat = ft_atoi(argv[5]);
		list->philo->check_num_eat = 1;
	}
	if (list->philo->num_philo % 2 != 0)
		list->philo->is_his_turn = 1;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_philolist	*make_list(int argc, char **argv)
{
	t_philolist	*list;
	t_philolist	*aux;
	t_philolist	*list_first;
	int			i;
	int			num_philos;

	list = NULL;
	i = 1;
	list = make_philo(i, argc, argv);
	list_first = list;
	num_philos = ft_atoi(argv[1]);
	while (i < num_philos)
	{
		list->next = make_philo(i + 1, argc, argv);
		aux = list;
		list = list->next;
		list->prev = aux;
		i++;
	}
	list->next = list_first;
	list_first->prev = list;
	list = list->next;
	return (list);
}
