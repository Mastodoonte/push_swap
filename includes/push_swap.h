/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:41:14 by florianma         #+#    #+#             */
/*   Updated: 2021/09/03 10:52:39 by flmastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_pusw
{
	int		*stack_a;
	int		len_a;
	int		*stack_b;
	int		len_b;
	int		*stack_sorted;
	int		len_stack_sorted;
	int		index_pivot;
	int		value_pivot;
	int		ps_count;
	int		push_now;
}	t_pusw;

void		error_gestion(char **av, int ac, long int **tab);
long int	ft_atoi(const char *str);
t_pusw		*init_0(t_pusw *info);
t_pusw		*initialize_info(int argc, t_pusw *info);
t_pusw		*get_array(long int *tab, t_pusw *info, int ac);
int			ft_is_already_sorted(t_pusw *info);
void		swap_a(t_pusw *info);
void		ft_swap(int *a, int *b);
void		display(t_pusw *info);
void		swap_a(t_pusw *info);
void		rev_rotate_a(t_pusw *info);
void		rotate_a(t_pusw *info);
void		rotate_b(t_pusw *info);
void		swap_3(t_pusw *info);
void		push_b(t_pusw *info);
void		rev_rotate_b(t_pusw *info);
void		rev_rotate_a(t_pusw *info);
void		rev_rotate_ab(t_pusw *info);
void		rotate_ab(t_pusw *info);
void		push_a(t_pusw *info);
void		push_b(t_pusw *info);
void		swap_ab(t_pusw *info);
void		swap_b(t_pusw *info);
void		ft_sort_int_tab(int *tab, int size);
int			get_index(t_pusw *info, int index);
void		ft_rev_int_tab(int *tab, int size);
void		final_push(t_pusw *info);
void		from_bottom_moove(t_pusw *info, int indice);
void		from_top_moove(t_pusw *info, int indice);
int			check_b(t_pusw *info, int start_chunk, int end_chunk);
int			check_t(t_pusw *info, int start_chunk, int end_chunk);
void		sort_100(t_pusw *info);
void		udr_2_100(t_pusw *info, int *start_chunk, int *end_chunk, int *i);
void		udr_100(t_pusw *info, int *start_chunk, int *end_chunk, int *i);
void		welcome_into_b(t_pusw *info, int start_chunk, int end_chunk);
void		sort_500(t_pusw *info);
void		sort_5(t_pusw *info);
void		sort_4(t_pusw *info);
int			ft_minimum(t_pusw *info, int value);
long int	ft_special_atoi(char *str);
int			ft_str_number(char *str, int sign);
int			ft_check_double(long int *tab, int size_max);
void		ft_final_push(t_pusw *info);
int			get_top_index_nbr(t_pusw *info);
void		get_biggest_to_top(t_pusw *info);
int			ft_check_arg(char **av);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c, int *final_size);
size_t		ft_strlen(const char *str);
void		free_all_success(t_pusw *info);
void		free_all_failure(t_pusw *info);
char		*args_to_string(char **argv);
void		free_all_failure(t_pusw *info);
void		wrong_input(long int *tab);
void		put_top_stack(t_pusw *info);
int			get_mini(t_pusw *info);

#endif
