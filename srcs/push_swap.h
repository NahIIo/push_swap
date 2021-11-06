/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:49:00 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 15:28:53 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/ft_conv.h"
# include "../libft/inc/ft_ctype.h"
# include "../libft/inc/ft_list.h"
# include "../libft/inc/ft_norm.h"
# include "../libft/inc/ft_sort.h"
# include "../libft/inc/ft_stdio.h"
# include "../libft/inc/ft_stdlib.h"
# include "../libft/inc/ft_string.h"
# include "../libft/inc/ft_tree.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		max_size;
	int		top;
	int		*items;
}				t_stack;

void	free_all(t_stack *a, t_stack *b, char **nbrs);
void	sort(t_stack *a, t_stack *b);
void	sort_few_nbrs(t_stack *a, t_stack *b);
char		**get_nbrs(char **av, int ac);
t_stack		*initialize(int size);
void		fill(t_stack *stack, char **ints);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		push_inst(t_stack *dst, t_stack *src);
void		push(t_stack *stack, int item);
int			is_sorted(t_stack *a, t_stack *b);
void		handle_error(void);
int			pop(t_stack *stack);
void		sort_b(t_stack *b);
void		put_smallest_to_top(t_stack *a, t_stack *b);
void		sort_many_nbrs(t_stack *a, t_stack *b);
int			**get_groups(t_stack *stack, int amount);
void		push_group(t_stack *a, t_stack *b, int *group);
void		push_and_sort_group(t_stack *b, t_stack *a, int *group);
int			has_members(t_stack *stack, int *group);
int			get_member_to_push_and_sort(t_stack *b, t_stack *a, int *group);
void		rotate_stacks(t_stack *b, t_stack *a, int items[2], int places[2]);
void		reverse_rotate_stacks(t_stack *b, t_stack *a, int items[2],
				int places[2]);
void		sort_a(t_stack *a);
int			get_smallest(t_stack *stack);
int			get_biggest(t_stack *stack);
int			get_mvs(t_stack *b, t_stack *a, int limits[2], int member);
int			get_mvs_2(int stuff[2], t_stack *a, t_stack *b, int member);

#endif
