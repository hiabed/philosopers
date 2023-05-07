#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
    struct s_data *data;
    int id;
    int r_fork;
    int l_fork;
   
   
    unsigned long last_meal;
} t_philo;

typedef struct s_data
{
    t_philo *data;
    time_t first_time;
    int t_eat;
    int t_sleep;
    int t_die;
    int n_philos;
    pthread_mutex_t *forks;
} t_data;

int	ft_atoi(const char *str);
unsigned long get_time_in_ms();

#endif