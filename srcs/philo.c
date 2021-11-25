/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:27:28 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/25 18:33:49 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*make_thread(void *param)
{
	t_philolist	*philo;

	philo = (t_philolist *)param;
	printf("Num filo: %d\n", philo->philo.num);
	return (NULL);
}

static void	make_args(t_philo *phil, int argc, char **argv)
{
	phil->num_philo = ft_atoi(argv[1]);
	phil->time_die = ft_atoi(argv[2]);
	phil->time_eat = ft_atoi(argv[3]);
	phil->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		phil->num_must_eat = ft_atoi(argv[5]);
	if (phil->num_philo < 1)
		print_error();
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
	t_philo		phil;
	t_philolist	*list;
	int			i;

	ft_bzero(&phil, sizeof(phil));
	if (check_args(argc, argv))
		return (1);
	make_args(&phil, argc, argv);
	list = create_list(&phil);
	i = 0;
	while (i < phil.num_philo)
	{
		pthread_create(&thread, NULL, make_thread, (void *)list);
		pthread_join(thread, NULL);
		list = list->next;
		i++;
	}
	return (0);
}
