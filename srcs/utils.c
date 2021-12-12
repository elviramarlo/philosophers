/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:41:19 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/12 20:39:08 by elvmarti         ###   ########.fr       */
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
			(int)present_time(list->philo->time) + 1, list->philo->num_philo);
	else if (c == 'f')
		printf(YELLOW"%d - Philosopher %d has taken a fork\n"RESET,
			(int)present_time(list->philo->time), list->philo->num_philo);
	else if (c == 'e')
		printf(CYAN"%d - Philosopher %d is eating\n"RESET,
			(int)present_time(list->philo->time), list->philo->num_philo);
	else if (c == 's')
		printf(PURPLE"%d - Philosopher %d is sleeping\n"RESET,
			(int)present_time(list->philo->time), list->philo->num_philo);
	else if (c == 't')
		printf(GREEN"%d - Philosopher %d is thinking\n"RESET,
			(int)present_time(list->philo->time), list->philo->num_philo);
	if (c != 'd' && !check_all_eat(list))
		pthread_mutex_unlock(&mutex_print);
}

time_t	present_time(time_t time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return (start.tv_sec * 1000 + start.tv_usec / 1000 - time);
}

void	ft_usleep(int time_of_action)
{
	time_t	start;

	start = present_time(0);
	while ((present_time(0) - start) < time_of_action)
		usleep(600);
}
