/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:50:00 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/13 00:39:09 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void *philo()
// {
//     int a = 4;
//     int b = 5;
//     printf("%d\n", a + b);
//     return NULL;
// }

// int main()
// {
//     pthread_t thread_1;
//     pthread_create(&thread_1, NULL, philo, NULL);
//     pthread_join(thread_1, NULL);
// }

typedef struct mutex
{
    pthread_mutex_t mutex;
    int count;
} t_mutex;

void *increment(void *arg) {
    int i = 0;
    
    t_mutex* m;
    m = (t_mutex *)arg;
    while(i < 1000000)
    {
        pthread_mutex_lock(&(m->mutex));
        m->count++;
        i++;
        pthread_mutex_unlock(&(m->mutex));
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    t_mutex m;
    m.count = 0;
    pthread_mutex_init(&(m.mutex), NULL);
    pthread_create(&t1, NULL, increment, &m);
    pthread_create(&t2, NULL, increment, &m);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("count = %d\n", m.count);

    pthread_mutex_destroy(&m.mutex);
    return 0;
}