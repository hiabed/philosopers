/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:34:09 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/07 23:50:51 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void store_info(t_data *ph)
{
    int i;
    //pthread_t philo[n_philos];
    //pthread_mutex_t forks[n_forks];
    // Initialize mutex locks for forks
    int j;
    j = 0;
    i = 1;
    ph->data = malloc(sizeof(t_philo) * ph->n_philos);
    while (i <= ph->n_philos)
    {
        if (i == ph->n_philos)
            ph->data[j].l_fork = 0;
        else
            ph->data[j].l_fork = i;
        ph->data[j].r_fork = i - 1;
        ph->data[j].id = i;
        ph->data[j].data = ph;
        i++;
        j++;
    }
}
unsigned long get_time_in_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void *ph_routine(void *arg)
{
    t_philo *ph = (t_philo *)arg;
   // printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    if(ph->id % 2 == 0)
        usleep(300);
    while (1)
    {
        // Check if the philosopher has died
        // if (get_time_in_ms() - ph->last_meal > ph->t_die)
        // {
        //     printf("%lu %d died\n", get_time_in_ms() - ph->last_meal, ph->id);
        //     exit(1);
        // }
        // Pick up the forks on their left and right
        //printf(">>>>>%lu\n",ph->forks[ph->l_fork]);
        pthread_mutex_lock(&ph->data->forks[ph->r_fork]);
       // printf(">>>l%d\n",ph->l_fork);
        printf("%lu %d has taken a fork\n", get_time_in_ms() - ph->data->first_time, ph->id);
        pthread_mutex_lock(&ph->data->forks[ph->l_fork]);
        //printf("<<<r%d\n",ph->r_fork);
        printf("%lu %d has taken a fork\n", get_time_in_ms() - ph->data->first_time, ph->id);
        // Philosopher is now eating
        printf("%lu %d is eating\n", get_time_in_ms() - ph->data->first_time, ph->id);
        usleep(ph->data->t_eat * 1000);
        
        // Put down the forks on their left and right
        //printf("%lu %d puts down the forks\n", get_time_in_ms() - ph->data->first_time, ph->id);
        pthread_mutex_unlock(&ph->data->forks[ph->l_fork]);
        pthread_mutex_unlock(&ph->data->forks[ph->r_fork]);
        
        // Philosopher is now sleeping
        printf("%lu %d is sleeping\n", get_time_in_ms() - ph->data->first_time, ph->id);
        usleep(ph->data->t_sleep * 1000);
        
        // Philosopher is now thinking
        printf("%lu %d is thinking\n", get_time_in_ms() - ph->data->first_time, ph->id);
    }
    return NULL;
}

int main(int ac, char *av[])
{
    int i;
    if(ac < 5 || ac > 6)
    {
        write(2, "you should enter 4 or 5 arguments\n", 42);
        exit(EXIT_FAILURE);
    }
    t_data *ph;
    
    ph = malloc(sizeof(t_data));
    ph->first_time = get_time_in_ms();
   // printf("------------\n");
    ph->n_philos = ft_atoi(av[1]);
    //ph->data = malloc(sizeof(t_philo) * n_philos);
    ph->t_die = ft_atoi(av[2]);
    ph->t_eat = ft_atoi(av[3]);
    ph->t_sleep = ft_atoi(av[4]);
    int n_times_eat;
    if(ac == 6)
        n_times_eat = ft_atoi(av[5]);
     pthread_t *philo = malloc(sizeof(pthread_t)*  ph->n_philos ) ;
    //int n_forks = n_philos;
    i = 0;
    store_info(ph);
    ph->forks = malloc(sizeof(pthread_mutex_t) * ph->n_philos);
    while(i < ph->n_philos)
    {
        pthread_mutex_init(&ph->forks[i], NULL);
        i++;
    }
    // if(n_philos < 1 || n_forks < 1)
    // {
    //     write(2, "there is no philosopher at the table\n", 37);
    //     exit(EXIT_FAILURE);
    // }
    i  = 0;
    // Create threads for each philosopher
    while(i < ph->n_philos)
    {
        ph->data[i].id = i + 1;
        // ph->data[i].t_eat = ft_atoi(av[3]);
        // ph->data[i].t_sleep = ft_atoi(av[4]);
        // ph->data[i].forks = &forks[i];
        // ph->data[i].last_meal = get_time_in_ms();
        pthread_create(&philo[i], NULL, ph_routine, &ph->data[i]);
        i++;
    }
    // Wait for all threads to complete
    i = 0;
    while (i < ph->n_philos) {
        pthread_join(philo[i], NULL);
        i++;
    }
    // Cleanup mutex locks
    // i = 0;
    // while (i < ph.n_philos) {
    //     pthread_mutex_destroy(&forks[i]);
    //     i++;
    // }
    //free(ph);
    return 0;
}
