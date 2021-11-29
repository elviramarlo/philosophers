/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:28:05 by elvmarti          #+#    #+#             */
/*   Updated: 2021/11/29 23:34:26 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_philo
{
	int				num_total_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				num_must_eat;
	int				check_num_eat;
	int				num_philo;
	int				philo_has_died;
	int				fork;
	pthread_mutex_t	mutex_fork;
	int				is_his_turn;
	time_t			time;
}			t_philo;

typedef struct s_philolist
{
	t_philo				philo;
	struct s_philolist	*next;
	struct s_philolist	*prev;
}				t_philolist;


t_philolist	*make_list(int argc, char **argv);
void		eat(t_philolist *list);
void		print_state(t_philolist *list, char c);

void		ft_usleep(int time_of_action);
 int		present_time(int time);

int			print_error();
int			ft_isdigit(int a);
void		ft_bzero(void *pt, size_t n);
int			ft_atoi(char *str);


# define RESET				"\x1b[0m"
# define WHITE				"\x1b[1m"
# define GRAY				"\x1b[2m"
# define BLACK				"\x1b[30m"
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define PURPLE				"\x1b[35m"
# define CYAN				"\x1b[36m"

#endif