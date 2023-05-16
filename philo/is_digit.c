/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:21 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/12 23:15:46 by mhassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_is_num(char **av)
{
	int	j;

	j = 1;
	while (av[j])
	{
		if (ft_atoi(av[j]) == -1)
		{
			write(2, "Please enter only positive numbers\n", 35);
			return (0);
		}
		if (ft_atoi(av[j]) == 0 || ft_atoi(av[j]) == -2 || ft_atoi(av[j]) == -3)
		{
			write(2, "Please enter only valid numbers\n", 32);
			return (0);
		}
		j++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && result <= INT32_MAX)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		return (-3);
	if (result > INT32_MAX)
		return (0);
	if (result == 0)
		return (-2);
	return (result);
}
