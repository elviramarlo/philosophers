/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:41:19 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/03 22:16:19 by elvmarti         ###   ########.fr       */
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
	static pthread_mutex_t	mutex_print = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mutex_print);
	if (c == 'd')
		printf(RED"%d - Philosopher %d died\n"RESET,
			present_time(list->philo->time), list->philo->num_philo);
	else if (c == 'f')
		printf(YELLOW"%d - Philosopher %d has taken a fork\n"RESET,
			present_time(list->philo->time), list->philo->num_philo);
	else if (c == 'e')
		printf(CYAN"%d - Philosopher %d is eating\n"RESET,
			present_time(list->philo->time), list->philo->num_philo);
	else if (c == 's')
		printf(PURPLE"%d - Philosopher %d is sleeping\n"RESET,
			present_time(list->philo->time), list->philo->num_philo);
	else if (c == 't')
		printf(GREEN"%d - Philosopher %d is thinking\n"RESET,
			present_time(list->philo->time), list->philo->num_philo);
	if (c != 'd')
		pthread_mutex_unlock(&mutex_print);
}

int	present_time(int time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000 + start.tv_usec / 1000 - time);
}

void	ft_usleep(int time_of_action)
{
	int	start;

	start = present_time(0);
	while ((present_time(0) - start) < time_of_action)
		usleep(100);
}
