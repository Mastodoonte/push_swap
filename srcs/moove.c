/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:28:58 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/01 16:22:58 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pusw *info)
{
	if (info->len_a > 0)
	{
		ft_swap(&info->stack_a[0], &info->stack_a[1]);
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_pusw *info)
{
	if (info->len_b > 0)
	{
		ft_swap(&info->stack_b[0], &info->stack_b[1]);
	}
	write(1, "sb\n", 3);
}

void	swap_ab(t_pusw *info)
{	
	if (info->len_a > 0 && info->len_b > 0)
	{
		ft_swap(&info->stack_a[0], &info->stack_a[1]);
		ft_swap(&info->stack_b[0], &info->stack_b[1]);
	}
	write(1, "ss\n", 3);
}

void	push_a(t_pusw *info)
{
	if (info->len_b >= 0)
	{
		info->len_a = info->len_a + 1;
		ft_rev_int_tab(info->stack_b, info->len_b + 1);
		ft_rev_int_tab(info->stack_a, info->len_a);
		info->stack_a[info->len_a] = info->stack_b[info->len_b];
		info->len_b = info->len_b - 1;
		ft_rev_int_tab(info->stack_b, info->len_b + 1);
		ft_rev_int_tab(info->stack_a, info->len_a + 1);
	}
	write(1, "pa\n", 3);
}

void	push_b(t_pusw *info)
{
	if (info->len_a >= 0)
	{
		info->len_b = info->len_b + 1;
		ft_rev_int_tab(info->stack_a, info->len_a + 1);
		ft_rev_int_tab(info->stack_b, info->len_b);
		info->stack_b[info->len_b] = info->stack_a[info->len_a];
		info->len_a = info->len_a - 1;
		ft_rev_int_tab(info->stack_a, info->len_a + 1);
		ft_rev_int_tab(info->stack_b, info->len_b + 1);
	}
	write(1, "pb\n", 3);
}
