/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:41:19 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/02 21:20:59 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	print_error(void)
{
	printf("Error\n");
	return (1);
}

void	print_state(t_philolist *list, char c)
{
	if (c == 'd')
		printf(RED"%d - Philosopher %d died\n"RESET,
			present_time(list->philo.time), list->philo.num_philo);
	else if (c == 'f')
		printf(YELLOW"%d - Philosopher %d has taken a fork\n"RESET,
			present_time(list->philo.time), list->philo.num_philo);
	else if (c == 'e')
		printf(CYAN"%d - Philosopher %d is eating\n"RESET,
			present_time(list->philo.time), list->philo.num_philo);
	else if (c == 's')
		printf(PURPLE"%d - Philosopher %d is sleeping\n"RESET,
			 present_time(list->philo.time), list->philo.num_philo);
	else if (c == 't')
		printf(GREEN"%d - Philosopher %d is thinking\n"RESET,
			present_time(list->philo.time), list->philo.num_philo);	
}

int	check_dead(t_philolist *list)
{
	t_philolist *aux;
	int i = 0;

	aux = list;
	while(i < aux->philo.num_total_philo)
	{
		if (aux->philo.philo_has_died)
			return (1);
		aux = aux->next;
		i++;
	}
	return (0);
}
