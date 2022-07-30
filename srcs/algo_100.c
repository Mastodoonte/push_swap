/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:39:59 by florianma         #+#    #+#             */
/*   Updated: 2021/09/01 15:56:22 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	udr_100(t_pusw *info, int *start_chunk, int *end_chunk, int *i)
{
	while ((*i < *end_chunk))
	{
		if (check_b(info, *start_chunk, *end_chunk)
			>= check_t(info, *start_chunk, *end_chunk))
		{
			from_bottom_moove(info, check_t(info, *start_chunk, *end_chunk));
		}
		else if (check_b(info, *start_chunk, *end_chunk)
			< check_t(info, *start_chunk, *end_chunk))
		{
			from_top_moove(info, check_b(info, *start_chunk, *end_chunk));
		}
		push_b(info);
		(*i)++;
	}
}

void	udr_2_100(t_pusw *info, int *start_chunk, int *end_chunk, int *i)
{
	while ((*i < *end_chunk + 1))
	{
		if (check_b(info, *start_chunk, *end_chunk)
			>= check_t(info, *start_chunk, *end_chunk))
		{
			from_bottom_moove(info, check_t(info, *start_chunk, *end_chunk));
		}
		else if (check_b(info, *start_chunk, *end_chunk)
			< check_t(info, *start_chunk, *end_chunk))
		{
			from_top_moove(info, check_b(info, *start_chunk, *end_chunk));
		}
		push_b(info);
		(*i)++;
	}
}

void	sort_100(t_pusw *info)
{
	int	i;
	int	start_chunk;
	int	chunk;
	int	j;
	int	end_chunk;

	chunk = ((info->len_a) + 1) / 5;
	start_chunk = 0;
	end_chunk = chunk;
	i = 0;
	j = 0;
	while (j < 5)
	{
		udr_100(info, &start_chunk, &end_chunk, &i);
		j++;
		start_chunk = i;
		end_chunk = end_chunk + chunk;
	}
	if ((info->len_a + 1) % 5 > 0)
	{
		end_chunk = end_chunk + ((info->len_stack_sorted) + 1) % 5;
		udr_2_100(info, &start_chunk, &end_chunk, &i);
	}
}
