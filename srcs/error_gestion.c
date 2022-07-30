/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 09:11:47 by florianma         #+#    #+#             */
/*   Updated: 2021/09/02 11:59:01 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_maxll(unsigned long long res, int signe)
{
	if (res > 9223372036854775807 && signe == 1)
		return (-1);
	else
		return (0);
}

long int	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	res;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807)
		return (ft_maxll(res, signe));
	return (res * signe);
}

long int	ft_special_atoi(char *str)
{
	int			i;
	long int	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && nb <= 2147483648)
		nb = ((nb * 10) + (str[i++] - '0'));
	nb *= neg;
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

int	ft_check_double(long int *tab, int size_max)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_max)
	{
		j = i + 1;
		while (j < size_max - 1)
		{
			if (tab[i] < -2147483648 || tab[i] > 2147483647)
				return (-1);
			if (tab[i] == tab[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_str_number(char *str, int sign)
{
	int	i;

	i = 0 + sign;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		++i;
	}
	return (0);
}
