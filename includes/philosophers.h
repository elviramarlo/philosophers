/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:28:05 by elvmarti          #+#    #+#             */
/*   Updated: 2021/12/12 18:59:52 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_philo
{
	int				num_total_philo;
	unsigned int	time_die;
	int				time_eat;
	int				time_sleep;
	int				num_must_eat;
	int				check_num_eat;
	int				num_philo;
	int				philo_has_died;
	time_t			the_last_supper;
	int				is_printing;
	int				fork;
	int				is_his_turn;
	time_t			time;
	pthread_mutex_t	mutex_fork;
}			t_philo;

typedef struct s_philolist
{
	t_philo				*philo;
	struct s_philolist	*next;
	struct s_philolist	*prev;
}				t_philolist;

t_philolist	*make_list(int argc, char **argv);
void		*make_thread(void *param);
int			eat(t_philolist *list);
int			philo_died(t_philolist *l);
int			check_death(t_philolist *list);
int			check_all_eat(t_philolist *list);
int			print_error(void);
void		print_state(t_philolist *list, char c);
time_t		present_time(time_t time);
void		ft_usleep(int time_of_action);
int			ft_isdigit(int a);
int			ft_atoi(char *str);
void		ft_bzero(void *pt, size_t n);

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