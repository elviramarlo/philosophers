/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:01:11 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/25 18:34:21 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philolist	*create_nodo(int i)
{
	t_philolist	*list;

	list = (t_philolist *)malloc(sizeof(t_philolist));
	list->philo.num = i;
	list->philo.fork = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_philolist	*create_list(t_philo *phil)
{
	t_philolist	*list;
	t_philolist	*aux;
	t_philolist	*list_first;
	int 		i;

	i = 1;
	list = (t_philolist *)malloc(sizeof(t_philolist));
	list = create_nodo(i);
	list_first = list;
	while (i < phil->num_philo)
	{
		list->next = create_nodo(i + 1);
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
	while (i < phil->num_philo)
	{
		printf("EL NUMERO DEL FILOSOFO ES %d\n", aux->philo.num);
		aux = aux->next;
		i++;
	}
} */
