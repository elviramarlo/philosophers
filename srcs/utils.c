/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:41:19 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/25 18:40:08 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
