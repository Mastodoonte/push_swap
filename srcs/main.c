/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:17:08 by florianma         #+#    #+#             */
/*   Updated: 2021/09/07 11:07:00 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] && str)
	{
		i++;
	}
	return (i);
}

void	alg_main(t_pusw *info)
{
	if (info->len_a == 1)
		swap_a(info);
	else if (info->len_a == 2)
		swap_3(info);
	else if (info->len_a == 3)
		sort_4(info);
	else if (info->len_a == 4)
		sort_5(info);
	else if (info->len_a > 4 && info->len_a <= 99)
	{
		sort_100(info);
		ft_final_push(info);
	}
	else if (info->len_a > 99)
	{
		sort_500(info);
		ft_final_push(info);
	}
}

void	free_all_success(t_pusw *info)
{
	if (info->stack_a)
		free(info->stack_a);
	if (info->stack_b)
		free(info->stack_b);
	if (info->stack_sorted)
		free(info->stack_sorted);
	if (info)
		free(info);
	info = NULL;
	exit (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	long int	*tab;
	t_pusw		*info;
	char		**as;
	char		*str;
	int			error;

	info = NULL;
	if (ac < 2)
		return (0);
	str = args_to_string(av);
	as = ft_split(str, ' ', &ac);
	free(str);
	error_gestion(as, ac, &tab);
	error = ft_check_arg(as);
	if (ft_check_double(tab, ac + 1) == -1 || error == 1 )
		wrong_input(tab);
	info = initialize_info(ac + 1, info);
	info = get_array(tab, info, ac);
	ft_sort_int_tab(info->stack_sorted, info->len_a);
	if (ft_is_already_sorted(info) == 1)
		alg_main(info);
	free_all_success(info);
	return (0);
}
