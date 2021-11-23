/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:27:28 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/23 18:52:17 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*make_thread(void *param)
{
	t_philo 	*phil;
	
	phil = (t_philo *)param;
	printf("Num filo: %d\n", phil->num_philo);
	return (NULL);
}

static void make_args(t_philo *phil, int argc, char **argv)
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

int main(int argc, char **argv)
{
	pthread_t	philo;
	t_philo		phil;
	int			i;
	
	ft_bzero(&phil, sizeof(phil));
	if (argc < 5 || argc > 6)
		print_error();
	make_args(&phil, argc, argv);
	i = 0;
	while (i < phil.num_philo)
	{
		pthread_create(&philo, NULL, make_thread, (void *)&phil);
		pthread_join(philo, NULL);
		i++;
	}
}
