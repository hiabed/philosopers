#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philo
{
    int id;
    int r_fork;
    int l_fork;
} t_philo;

typedef struct s_data
{
    t_philo *data;
    pthread_mutex_t mutex;
    int count;
} t_data;

int	ft_atoi(const char *str);
unsigned long get_time_in_ms();

#endif