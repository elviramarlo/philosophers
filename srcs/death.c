/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:42:49 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/03 15:48:02 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static	void	is_dead(t_philolist *l, unsigned int time)
{
	if ((present_time(0) - time) >= l->philo->time_die)
	{
		print_state(l, 'd');
		l->philo->philo_has_died = 1;
	}
}

int	philo_died(t_philolist *l)
{
	int	i;

	i = 0;
	while (i < l->philo->num_total_philo)
	{
		if (l->philo->the_last_supper)
			is_dead(l, l->philo->the_last_supper);
		else
			is_dead(l, l->philo->time);
		if (l->philo->philo_has_died || (l->philo->check_num_eat
				&& !l->philo->num_must_eat))
			return (1);
		l = l->next;
		i++;
	}
	return (0);
}

int	check_death(t_philolist *list)
{
	t_philolist	*aux;
	int			i;

	i = 0;
	aux = list;
	while (i < aux->philo->num_total_philo)
	{
		if (aux->philo->philo_has_died)
			return (1);
		aux = aux->next;
		i++;
	}
	return (0);
}
