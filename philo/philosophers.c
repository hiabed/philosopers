/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:34:09 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/02 23:00:44 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philos()
{
    printf("philo's created\n");
    return NULL;
}

int main(int ac, char *av[])
{
    if(ac < 4)
    {
        write(2, "you should enter exactly 4 or 5 arguments\n", 42);
        exit(EXIT_FAILURE);
    }
    int n_philos = ft_atoi(av[1]);
    int n_forks = n_philos;
    int i = 0;
    pthread_t philo[n_philos];
    if(n_philos < 1 || n_forks < 1)
    {
        write(2, "there is no philosopher at the table\n", 37);
        exit(EXIT_FAILURE);
    }
    while(i < n_philos)
    {
        pthread_create(&philo[i], NULL, philos, NULL);
        pthread_join(philo[i], NULL);
        i++;
    }

    return 0;
}
