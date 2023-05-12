/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:50:00 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/12 17:06:46 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>

typedef struct s_mutex
{
	int				count;
	pthread_mutex_t	mutex;
}					t_mutex;

void	*increment(void *arg)
{
	int		i;
	t_mutex	*m;

	i = 0;
	m = (t_mutex *)arg;
	// printf("1: %p\n", &m->count);
	while (i < 1000000)
	{
		pthread_mutex_lock(&(m->mutex));
		m->count++;
		i++;
		pthread_mutex_unlock(&(m->mutex));
	}
	return (NULL);
}

int	main(void)
{
	pthread_t t1, t2;
	t_mutex m;
	m.count = 0;
	// printf("2: %p\n", &m.count);
	pthread_mutex_init(&(m.mutex), NULL);
	pthread_create(&t1, NULL, increment, &m);
	pthread_create(&t2, NULL, increment, &m);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("count = %d\n", m.count);

	pthread_mutex_destroy(&m.mutex);
	return (0);
}