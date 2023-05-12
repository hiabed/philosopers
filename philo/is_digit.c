/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhassani <mhassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:21 by mhassani          #+#    #+#             */
/*   Updated: 2023/05/12 16:56:58 by mhassani         ###   ########.fr       */
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
			write(2, "Please enter only valid numbers\n", 32);
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
		if (ft_atoi(av[j]) == 1)
		{
			write(2, "Please enter only positive numbers\n", 35);
			return (0);
		}
		if (ft_atoi(av[j]) == 0)
		{
			write(2, "Please enter only numbers less than max int\n", 44);
			return (0);
		}
		if (!is_num(av[j]))
			return (0);
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
		return (1);
	if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && result <= INT32_MAX)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > INT32_MAX)
		return (0);
	return (result);
}
