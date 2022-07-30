/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:54:51 by florianma         #+#    #+#             */
/*   Updated: 2021/09/02 15:25:44 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_is_already_sorted(t_pusw *info)
{
	int	i;

	i = info->len_a;
	if (info->len_b != -1)
		return (0);
	while (i > 0)
	{
		if (info->stack_a[i - 1] > info->stack_a[i])
			return (1);
		i--;
	}
	return (0);
}

void	ft_final_push(t_pusw *info)
{
	while (info->len_b + 1 != 0)
	{
		get_biggest_to_top(info);
		push_a(info);
	}
}

int	get_top_index_nbr(t_pusw *info)
{
	int		i;
	int		biggest_index;

	i = 0;
	biggest_index = i;
	while (i < info->len_b + 1)
	{
		if (info->stack_b[i] > info->stack_b[biggest_index])
			biggest_index = i;
		i++;
	}
	return (biggest_index);
}

void	get_biggest_to_top(t_pusw *info)
{
	int		top_nbr_index;

	top_nbr_index = get_top_index_nbr(info);
	while (top_nbr_index != 0)
	{
		if (top_nbr_index <= ((info->len_b + 1) / 2))
			rotate_b(info);
		else
			rev_rotate_b(info);
		top_nbr_index = get_top_index_nbr(info);
	}
}
