/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:06:01 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/01 16:33:54 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pusw *info)
{
	int	len;
	int	tmp;

	tmp = info->stack_a[0];
	len = 0;
	if (info->len_a > 0)
	{
		while (len < info->len_a)
		{
			info->stack_a[len] = info->stack_a[len + 1];
			len++;
		}
		info->stack_a[info->len_a] = tmp;
	}
	write(1, "ra\n", 3);
}

void	rotate_b(t_pusw *info)
{
	int	len;
	int	tmp;

	tmp = info->stack_b[0];
	len = 0;
	if (info->len_b > 0)
	{
		while (len < info->len_b)
		{
			info->stack_b[len] = info->stack_b[len + 1];
			len++;
		}
		info->stack_b[info->len_b] = tmp;
	}
	write(1, "rb\n", 3);
}

void	rotate_ab(t_pusw *info)
{
	int	len;
	int	tmp;

	tmp = info->stack_a[0];
	len = 0;
	if (info->len_a > 0)
	{
		while (len < info->len_a)
		{
			info->stack_a[len] = info->stack_a[len + 1];
			len++;
		}
		info->stack_a[info->len_a] = tmp;
	}
	tmp = info->stack_b[0];
	len = 0;
	if (info->len_b > 0)
	{
		while (len++ < info->len_b)
		{
			info->stack_b[len] = info->stack_b[len + 1];
		}
		info->stack_b[info->len_b] = tmp;
	}
	write(1, "rr\n", 3);
}
