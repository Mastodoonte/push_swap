/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gestion2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:19:57 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/07 11:09:46 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_arg(char **as)
{
	char	sign;
	int		i;

	i = 0;
	while (as[i])
	{
		sign = 0;
		if (as[i][0] == '-')
			sign = 1;
		if (ft_strlen(as[i] + sign) == 0)
			return (1);
		if (ft_special_atoi(as[i]) == 0)
			return (1);
		if (ft_str_number(as[i], sign) == 1)
			return (1);
		free(as[i]);
		i++;
	}
	return (0);
}

void	error_gestion(char **as, int ac, long int **tab)
{
	int			i;
	long int	*tab1;

	tab1 = NULL;
	tab1 = (long int *)malloc(ac * sizeof(long int));
	if (!tab1)
	{
		free(tab1);
		free(tab);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (as[i])
	{
		tab1[i] = ft_atoi(as[i]);
		i++;
	}
	*tab = tab1;
}

void	wrong_input(long int *tab)
{
	write(1, "Error\n", 6);
	free(tab);
	exit(EXIT_FAILURE);
}

void	free_all_failure(t_pusw *info)
{
	if (info->stack_a)
		free(info->stack_a);
	if (info->stack_b)
		free(info->stack_b);
	if (info->stack_sorted)
		free(info->stack_sorted);
	if (info)
		free(info);
	info = NULL;
	exit (EXIT_FAILURE);
}

char	*args_to_string(char **argv)
{
	char	*str;
	char	*temp;
	int		i;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	*str = 0;
	temp = NULL;
	i = 1;
	while (argv[i])
	{
		temp = ft_strjoin(str, argv[i]);
		free(str);
		str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (str);
}
