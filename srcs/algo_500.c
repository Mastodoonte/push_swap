/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:39:59 by florianma         #+#    #+#             */
/*   Updated: 2021/09/02 09:45:48 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_500(t_pusw *info)
{
	int	i;
	int	start_chunk;
	int	chunk;
	int	j;
	int	end_chunk;

	chunk = ((info->len_a) + 1) / 11;
	start_chunk = 0;
	end_chunk = chunk;
	i = 0;
	j = 0;
	while (j < 11)
	{
		udr_100(info, &start_chunk, &end_chunk, &i);
		j++;
		start_chunk = i;
		end_chunk = end_chunk + chunk;
	}
	if ((info->len_a + 1) % 11 > 0)
	{
		end_chunk = end_chunk + ((info->len_stack_sorted) + 1) % 11;
		udr_2_100(info, &start_chunk, &end_chunk, &i);
	}
}
