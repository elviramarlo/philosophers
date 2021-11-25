/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:28:05 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/25 18:38:14 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_must_eat;
}			t_philo;

typedef struct s_data_philo
{
	int	num;
	int	fork;
}			t_data_philo;


typedef struct s_philolist
{
	t_data_philo		philo;
	struct s_philolist	*next;
	struct s_philolist	*prev;
}				t_philolist;

t_philolist	*create_list();
int			print_error();

int	ft_isdigit(int a);
void	ft_bzero(void *pt, size_t n);
int	ft_atoi(char *str);

#endif