/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:28:05 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/23 18:47:15 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_must_eat;
}			t_philo;

typedef struct s_philolist
{
	void				*content;
	struct s_philolist	*next;
	struct s_philolist	*prev;
}				t_philolist;

int	print_error();

#endif