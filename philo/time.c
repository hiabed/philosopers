/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:11:44 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/10 20:20:49 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	timee(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(unsigned int t)
{
	long int	time;

	time = timee();
	while (timee() - time < t)
		usleep(t / 10);
}

int	check_death(t_philo *ph)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < ph->data->n_philos)
		{
			pthread_mutex_lock(&ph->data->mutex);
			if (timee() - ph[i].last_meal >= ph->data->t_die)
			{
				pthread_mutex_lock(&ph->data->print);
				if (ph->data->n_times_eat == -1)
					printf("%lu %d  died\n", timee() - ph->data->first_time,
						ph[i].id);
				return (0);
			}
			pthread_mutex_unlock(&ph->data->mutex);
			i++;
		}
		return (1);
	}
}

void	ft_end(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_detach(data->philo[i]);
		i++;
	}
	while (1)
	{
		if (!check_death(data->ph))
		{
			break ;
		}
	}
}
