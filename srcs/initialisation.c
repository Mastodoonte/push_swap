/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:35:36 by florianma         #+#    #+#             */
/*   Updated: 2021/09/02 15:56:30 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

t_pusw	*init_0(t_pusw *info)
{
	info->stack_a = NULL;
	info->len_a = 0;
	info->stack_b = NULL;
	info->len_b = 0;
	info->index_pivot = 0;
	info->ps_count = 0;
	info->value_pivot = 0;
	return (info);
}

t_pusw	*initialize_info(int ac, t_pusw *info)
{

	info = NULL;
	info = (t_pusw *)malloc(sizeof(t_pusw));
	if (!info)
		free_all_failure(info);
	info->stack_a = (int *)malloc(sizeof(int) * ac);
	if (!info->stack_a)
		free_all_failure(info);
	info->stack_b = (int *)malloc(sizeof(int) * ac);
	if (!info->stack_b)
		free_all_failure(info);
	info = init_0(info);
	info->len_a = ac - 2;
	info->len_b = -1;
	info->len_stack_sorted = ac - 2;
	return (info);
}

t_pusw	*get_array(long int *tab, t_pusw *info, int ac)
{
	int	i;
	int	*tab1;
	int	*tab2;
	int	*tab3;

	tab1 = (int *)malloc(sizeof(int) * ac);
	tab2 = (int *)malloc(sizeof(int) * ac);
	tab3 = (int *)malloc(sizeof(int) * ac);
	if (!tab1 | !tab2 | !tab3)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < ac)
		tab1[i] = (int)tab[i];
	i = -1;
	while (++i < ac)
		tab2[i] = 0;
	i = -1;
	while (++i < ac)
		tab3[i] = (int)tab[i];
	info->stack_b = tab2;
	info->stack_a = tab1;
	info->stack_sorted = tab3;
	return (info);
}
