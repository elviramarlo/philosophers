/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:27:28 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/29 23:38:19 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*make_thread(void *param)
{
	t_philolist	*list;

	list = (t_philolist *)param;
	eat(list);
	return (NULL);
}

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
	return (0);
}

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
	if (list->philo.check_num_eat)
	{
		while (list->philo.num_must_eat)	
			pthread_join(thread, NULL);
	}
	else
		pthread_join(thread, NULL);
	return (0);
}
