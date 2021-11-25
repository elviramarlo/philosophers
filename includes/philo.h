/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:28:05 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/25 23:54:48 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int	num_total_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_must_eat;
	int	num_eat;
	int	num_philo;
	int	fork;
	float	time;
	struct timeval	i_time;
	struct timeval	f_time;
}			t_philo;


typedef struct s_philolist
{
	t_philo		philo;
	struct s_philolist	*next;
	struct s_philolist	*prev;
}				t_philolist;



t_philolist	*make_list(int argc, char **argv);
void		calculate_time(t_philolist *l);

int			print_error();
int			ft_isdigit(int a);
void		ft_bzero(void *pt, size_t n);
int			ft_atoi(char *str);

#endif