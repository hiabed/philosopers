/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:34:09 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/11 23:12:31 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_info(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	data->ph = malloc(sizeof(t_philo) * data->n_philos);
	while (i <= data->n_philos)
	{
		if (i == data->n_philos)
			data->ph[j].l_fork = 0;
		else
			data->ph[j].l_fork = i;
		data->ph[j].r_fork = i - 1;
		data->ph[j].id = i;
		data->ph[j].data = data;
		i++;
		j++;
	}
}

void	creat_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(pthread_t) * data->n_philos);
	while (i < data->n_philos)
	{
		data->ph[i].last_meal = timee();
		pthread_create(&data->philo[i], NULL, ph_routine, &data->ph[i]);
		i++;
	}
}

void	*ph_routine(void *arg)
{
	t_philo	*ph;
	int		i;

	i = 0;
	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(300);
	while (ph->data->n_times_eat == -1)
		mutexes(ph);
	while (i < ph->data->n_times_eat)
	{
		mutexes(ph);
		i++;
	}
	return (NULL);
}

void	get_args(t_data *data, int ac, char **av)
{
	data->first_time = timee();
	data->n_philos = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->n_times_eat = -1;
	if (ac == 6)
		data->n_times_eat = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	int		i;
	t_data	*data;

	if (ac < 5 || ac > 6)
	{
		write(2, "you should enter 4 or 5 arguments\n", 34);
		return (0);
	}
	if (!args_is_num(av))
		return (0);
	data = malloc(sizeof(t_data));
	get_args(data, ac, av);
	if (data->n_philos < 1)
	{
		write(2, "there is no philosopher at the table\n", 37);
		return (0);
	}
	philo_info(data);
	init_mutexes(data);
	creat_philos(data);
	ft_end(data);
}
