/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:21:05 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/14 14:19:58 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				r_fork;
	int				l_fork;
	unsigned long	last_meal;
}					t_philo;

typedef struct s_data
{
	t_philo			*ph;
	unsigned long	first_time;
	int				t_eat;
	int				t_sleep;
	unsigned long	t_die;
	int				n_times_eat;
	int				n_philos;
	int				eating;
	pthread_t		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	mutex2;
}					t_data;

int					check_death(t_philo *ph);
void				*ph_routine(void *arg);
void				philo_info(t_data *ph);
int					ft_atoi(const char *str);
unsigned long		timee(void);
void				ft_usleep(unsigned long t);
void				ft_end(t_data *data);
void				get_args(t_data *data, int ac, char **av);
void				mutexes(t_philo *ph);
void				creat_philos(t_data *data);
void				init_mutexes(t_data *data);
int					args_is_num(char **av);
#endif