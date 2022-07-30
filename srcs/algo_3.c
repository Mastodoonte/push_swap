/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:29:32 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/02 22:05:33 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_sorted(t_pusw *info)
{
	int	i;

	i = info->len_a;
	while (i > 0)
	{
		if (info->stack_a[i - 1] > info->stack_a[i])
			return (1);
		i--;
	}
	return (0);
}

void	sort_5(t_pusw *info)
{
	int	i;

	i = 0;
	while (info->len_a >= 3)
	{
		put_top_stack(info);
		push_b(info);
		i++;
	}
	if (is_already_sorted(info) == 1)
		swap_3(info);
	while (i > 0)
	{
		push_a(info);
		i--;
	}
}

void	sort_4(t_pusw *info)
{
	if (ft_is_already_sorted(info) == 1)
	{
		if (info->len_a > 0)
		{
			while (info->stack_a[0] != info->stack_sorted[3])
				rotate_a(info);
			push_b(info);
			swap_3(info);
			push_a(info);
			rotate_a(info);
		}
	}
}

void	swap_3(t_pusw *info)
{
	if (info->len_a > 0)
	{
		if (info->stack_a[0] > info->stack_a[1]
			&& info->stack_a[1] < info->stack_a[2]
			&& info->stack_a[0] < info->stack_a[2])
			swap_a(info);
		else if (info->stack_a[0] > info->stack_a[1]
			&& info->stack_a[1] > info->stack_a[2])
		{
			swap_a(info);
			rev_rotate_a(info);
		}
		else if (info->stack_a[0] > info->stack_a[1]
			&& info->stack_a[1] < info->stack_a[2])
			rotate_a(info);
		else if (info->stack_a[0] < info->stack_a[1]
			&& info->stack_a[0] < info->stack_a[2]
			&& info->stack_a[1] > info->stack_a[2])
		{
			swap_a(info);
			rotate_a(info);
		}
		else
			rev_rotate_a(info);
	}
}
