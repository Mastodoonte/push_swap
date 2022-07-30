/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:12:58 by florianma         #+#    #+#             */
/*   Updated: 2021/09/02 22:06:35 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int		swap;
	int		count;

	count = 0;
	while (count < (size))
	{
		if (tab[count] > tab[count + 1])
		{
			swap = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = swap;
			count = 0;
		}
		else
			count++;
	}
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	size--;
	while (i < size)
	{
		tmp = tab[i];
		tab[i] = tab[size];
		tab[size] = tmp;
		i++;
		size--;
	}
}

int	get_index(t_pusw *info, int index)
{
	int	i;

	i = 0;
	while (i < info->len_a + 1)
	{
		if (info->stack_sorted[index] == info->stack_a[i])
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int	get_mini(t_pusw *info)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < info->len_a + 1)
	{
		if (info->stack_a[index] > info->stack_a[i])
			index = i;
		i++;
	}
	return (index);
}

void	put_top_stack(t_pusw *info)
{
	int		mini_index;

	mini_index = get_mini(info);
	while (mini_index != 0)
	{
		if (mini_index > 2)
			rev_rotate_a(info);
		else
			rotate_a(info);
		mini_index = get_mini(info);
	}
}
