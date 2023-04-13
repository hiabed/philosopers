/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:34:09 by mhassani          #+#    #+#             */
/*   Updated: 2023/04/12 00:09:22 by mhassani         ###   ########.fr       */
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
        write(2, "you should enter exaactly 4 arguments\n", 38);
        exit(EXIT_FAILURE);
    }
    int n_philos = ft_atoi(av[1]);
    int n_forks = ft_atoi(av[1]);
    int i = 0;
    if(n_philos < 1 || n_forks < 1)
    {
        write(2, "there is no philosopher at the table\n", 37);
        exit(EXIT_FAILURE);
    }
    while(i < n_philos)
    {
        pthread_t philo[i];
        pthread_create(&philo[i], NULL, philos, NULL);
        pthread_join(philo[i], NULL);
        i++;
    }
    // only (n_philos / 2) can eat at the same time;
    i = 0;
    while (i < (n_philos / 2))
    {
        
        i++;
    }
    return 0;
}
