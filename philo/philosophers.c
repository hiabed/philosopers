/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:34:09 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/03 23:52:59 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// unsigned long get_time_in_ms()
// {
//     struct timeval tv;
//     gettimeofday(&tv, NULL);
//     return tv.tv_sec * 1000 + tv.tv_usec / 1000;
// }

// void *philos()
// {
//     printf("philo's created\n");
//     return NULL;
// }

void *philos(void *arg)
{
    int *num = (int *)arg;
    printf("philo %d created\n", *num);
    return NULL;
}

int main(int ac, char *av[])
{
    if(ac < 5 || ac > 6)
    {
        write(2, "you should enter 4 or 5 arguments\n", 42);
        exit(EXIT_FAILURE);
    }
    int n_philos = ft_atoi(av[1]);
    int t_die = ft_atoi(av[2]);
    int t_eat = ft_atoi(av[3]);
    int t_sleep = ft_atoi(av[4]);
    int n_times_eat;
    if(ac == 6)
    {
        n_times_eat = ft_atoi(av[5]);
    }
    int n_forks = n_philos;
    int i = 0;
    pthread_t philo[n_philos];
    pthread_mutex_t forks[n_philos];
    t_data * ph;
    ph = malloc(sizeof(t_data));
    int j;
    j = 1;
    while (i < n_philos)
    {
        // if ()
        // {
        //     /* code */
        // }
        
        ph->data[i].l_fork = j;
        ph->data[i].r_fork = j -1;
        ph->data[i].id = j;
        i++;
        j++;
    }
    
    // Initialize mutex locks for forks
    while(i < n_forks)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }

    if(n_philos < 1 || n_forks < 1)
    {
        write(2, "there is no philosopher at the table\n", 37);
        exit(EXIT_FAILURE);
    }
    i  = 0;
    // Create threads for each philosopher
    while(i < n_philos)
    {
        pthread_create(&philo[i], NULL, philos, &i);
        i++;
    }

    // Wait for all threads to complete
    i = 0;
    while (i < n_philos) {
        pthread_join(philo[i], NULL);
        i++;
    }

    // Cleanup mutex locks
    i = 0;
    while (i < n_philos) {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }

    return 0;
}
