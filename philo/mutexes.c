/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:10:24 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/11 23:12:43 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex, NULL);
	pthread_mutex_init(&data->print, NULL);
}

void	mutexes(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->forks[ph->r_fork]);
	pthread_mutex_lock(&ph->data->print);
	printf("%lu %d has taken a fork\n", timee() - ph->data->first_time, ph->id);
	pthread_mutex_unlock(&ph->data->print);
	pthread_mutex_lock(&ph->data->forks[ph->l_fork]);
	pthread_mutex_lock(&ph->data->print);
	printf("%lu %d has taken a fork\n", timee() - ph->data->first_time, ph->id);
	pthread_mutex_unlock(&ph->data->print);
	pthread_mutex_lock(&ph->data->mutex);
	ph->last_meal = timee();
	pthread_mutex_unlock(&ph->data->mutex);
	pthread_mutex_lock(&ph->data->print);
	printf("%lu %d is eating\n", timee() - ph->data->first_time, ph->id);
	pthread_mutex_unlock(&ph->data->print);
	ft_usleep(ph->data->t_eat);
	pthread_mutex_unlock(&ph->data->forks[ph->l_fork]);
	pthread_mutex_unlock(&ph->data->forks[ph->r_fork]);
	pthread_mutex_lock(&ph->data->print);
	printf("%lu %d is sleeping\n", timee() - ph->data->first_time, ph->id);
	pthread_mutex_unlock(&ph->data->print);
	ft_usleep(ph->data->t_sleep);
	pthread_mutex_lock(&ph->data->print);
	printf("%lu %d is thinking\n", timee() - ph->data->first_time, ph->id);
	pthread_mutex_unlock(&ph->data->print);
}
