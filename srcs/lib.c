/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:19:17 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/09 18:02:35 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
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

void	ft_bzero(void *pt, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)pt)[i] = '\0';
		i++;
	}
}
