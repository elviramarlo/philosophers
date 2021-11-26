/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:01:11 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/26 16:58:30 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philolist	*make_philo(int i, int argc, char **argv)
{
	t_philolist	*list;

	list = (t_philolist *)malloc(sizeof(t_philolist));
	list->philo.num_total_philo = ft_atoi(argv[1]);
	list->philo.time_die = ft_atoi(argv[2]);
	list->philo.time_eat = ft_atoi(argv[3]);
	list->philo.time_sleep = ft_atoi(argv[4]);
	list->philo.num_philo = i;
	list->philo.fork = 0;
	if (argc == 6)
		list->philo.num_must_eat = ft_atoi(argv[5]);
	if (list->philo.num_total_philo < 1)
		print_error();
	if (list->philo.num_philo % 2 == 0)
		list->philo.is_his_turn = 1;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_philolist	*make_list(int argc, char **argv)
{
	t_philolist	*list;
	t_philolist	*aux;
	t_philolist	*list_first;
	int 		i;
	int			num_philos;

	list = (t_philolist *)malloc(sizeof(t_philolist));
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

/* void	print_list(t_philolist *list, t_philo *phil)
{
	t_philolist *aux;
	int			i;

	i = 0;
	aux = list;
	while (i < list->philo.num_philo)
	{
		printf("EL NUMERO DEL FILOSOFO ES %d\n", aux->philo.num);
		aux = aux->next;
		i++;
	}
} */
