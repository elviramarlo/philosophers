/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:41:19 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/29 23:37:05 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void print_state(t_philolist *list, char c)
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

int	print_error(void)
{
	printf("Error\n");
	return (1);
}

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}

void	ft_bzero(void *pt, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)pt)[i] = '\0';
		i++;
	}
}

int	ft_atoi(char *str)
{
	long long int	signo;
	long long int	sol;

	signo = 1;
	sol = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signo = -signo;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (sol * signo > 2147483648)
			return (-1);
		else if (sol * signo < -2147483648)
			return (0);
		sol = sol * 10 + (*str - 48);
		str++;
	}
	return (signo * sol);
}
