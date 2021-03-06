/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:27:28 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/12 20:36:57 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	check_args(int argc, char **argv)
{
	int	i;
	int	y;

	if (argc < 5 || argc > 6)
		return (print_error());
	i = 1;
	while (argv[i])
	{
		y = 0;
		while (argv[i][y])
		{
			if (!ft_isdigit(argv[i][y]))
				return (print_error());
			y++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (print_error());
	return (0);
}

/* void	leaks(void)
{
	system("leaks philo");
}
atexit(leaks); */

int	main(int argc, char **argv)
{
	pthread_t	thread;
	t_philolist	*list;
	int			i;

	if (check_args(argc, argv))
		return (1);
	list = make_list(argc, argv);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&thread, NULL, make_thread, (void *)list);
		list = list->next;
		i++;
	}
	while (!philo_died(list))
		continue ;
	return (0);
}
