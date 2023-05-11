/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:21 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/11 13:27:16 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}

int	is_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			write(2, "Please enter only numbers\n", 26);
			return (0);
		}
		i++;
	}
	return (1);
}

int	args_is_num(char **av)
{
	int	j;

	j = 1;
	while (av[j])
	{
		if (!is_num(av[j]))
			return (0);
		j++;
	}
	return (1);
}
