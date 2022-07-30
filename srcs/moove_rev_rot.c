/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_rev_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:04:57 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/01 16:32:09 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_pusw *info)
{
	int	len;
	int	tmp;

	tmp = info->stack_a[info->len_a];
	len = info->len_a - 1;
	if (info->len_a > 0)
	{
		while (len >= 0 )
		{
			info->stack_a[len + 1] = info->stack_a[len];
			len--;
		}
		info->stack_a[0] = tmp;
	}
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_pusw *info)
{
	int	len;
	int	tmp;

	tmp = info->stack_b[info->len_b];
	len = info->len_b - 1;
	if (info->len_b > 0)
	{
		while (len >= 0 )
		{
			info->stack_b[len + 1] = info->stack_b[len];
			len--;
		}
		info->stack_b[0] = tmp;
	}
	write(1, "rrb\n", 4);
}

void	rev_rotate_ab(t_pusw *info)
{
	int	len;
	int	tmp;

	tmp = info->stack_a[info->len_a];
	len = info->len_a - 1;
	if (info->len_a > 0)
	{
		while (len >= 0 )
		{
			info->stack_a[len + 1] = info->stack_a[len];
			len--;
		}
		info->stack_a[0] = tmp;
	}
	tmp = info->stack_b[info->len_b];
	len = info->len_b - 1;
	if (info->len_b > 0)
	{
		while (len-- >= 0 )
			info->stack_b[len + 1] = info->stack_b[len];
		info->stack_b[0] = tmp;
	}
	write(1, "rrr\n", 4);
}
