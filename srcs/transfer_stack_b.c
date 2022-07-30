/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmastor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 18:37:14 by flmastor          #+#    #+#             */
/*   Updated: 2021/09/01 16:50:49 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_bottom_moove(t_pusw *info, int indice)
{
	int	i;

	i = 0;

	info->push_now = 0;
	while (i < indice)
	{
		rotate_a(info);
		i++;
	}
}

void	from_top_moove(t_pusw *info, int indice)
{
	int	i;

	i = 0;
	while (i <= indice)
	{
		rev_rotate_a(info);
		i++;
	}
}

int	check_stack_sorted(t_pusw *info, int start_chunk, int end_chunk, int number)
{
	int	i;

	i = start_chunk;
	while (i < end_chunk)
	{
		if (number == info->stack_sorted[i])
		{
			info->value_pivot = info->stack_sorted[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_b(t_pusw *info, int start_chunk, int end_chunk)
{
	int	i;
	int	value;

	i = info->len_a;
	value = 0;
	while (i >= 0)
	{
		if (check_stack_sorted(info, start_chunk,
				 end_chunk, info->stack_a[i]) == 1)
			return (value);
		i--;
		value++;
	}
	return (0);
}

int	check_t(t_pusw *info, int start_chunk, int end_chunk)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (i <= info->len_a)
	{
		if (check_stack_sorted(info, start_chunk, end_chunk,
				info->stack_a[i]) == 1)
			return (value);
		i++;
		value++;
	}
	return (0);
}
