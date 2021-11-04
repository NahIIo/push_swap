/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:00:42 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:03:12 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shortest_rotation(t_stack **stack_b, t_all *all, int pos)
{
	int	i;

	i = -1;
	if (pos <= all->size_b / 2)
	{
		while (++i < pos)
			rb(stack_b, all);
	}
	else
	{
		while (++i < all->size_b - pos)
			rrb(stack_b, all);
	}
}

static void	move_max_to_top(t_stack **stack_b, t_all *all)
{
	int		pos;
	int		max;
	t_stack	*tmp;

	tmp = (*stack_b);
	max = ft_lstmax_num(stack_b);
	pos = 0;
	while (tmp)
	{
		if (tmp->num == max)
			break ;
		pos++;
		tmp = tmp->next;
	}
	shortest_rotation(stack_b, all, pos);
}

static void	adjust_stack_b(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	t_stack	*tmp;
	int		pos;
	int		min_b;
	int		max_b;
	int		top_a;

	pos = 0;
	min_b = ft_lstmin_num(stack_b);
	max_b = ft_lstmax_num(stack_b);
	top_a = (*stack_a)->num;
	tmp = (*stack_b);
	if (top_a < min_b || top_a > max_b)
		return (move_max_to_top(stack_b, all));
	while (tmp)
	{
		pos++;
		if (tmp->next && (top_a < tmp->num && top_a > tmp->next->num))
			break ;
		tmp = tmp->next;
	}
	shortest_rotation(stack_b, all, pos);
}

static void	sort_each_chunk(t_stack **stack_a, t_stack **stack_b,
				t_all *all, int chunk_max)
{
	while ((stack_has(stack_a, chunk_max)))
	{
		if ((*stack_a)->num <= chunk_max)
		{
			adjust_stack_b(stack_a, stack_b, all);
			pb(stack_a, stack_b, all);
		}
		else
			ra(stack_a, all);
	}
	move_max_to_top(stack_b, all);
}

void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	int	chunk_max;
	int	how_many_chunk;
	int	i;

	chunk_max = 0;
	i = 0;
	how_many_chunk = 5;
	if (all->size_a > 200)
		how_many_chunk = 11;
	chunk_max = (ft_lstmax_num(stack_a) - ft_lstmin_num(stack_a))
		/ how_many_chunk;
	while (++i < how_many_chunk)
		sort_each_chunk(stack_a, stack_b, all, chunk_max * i);
	sort_each_chunk(stack_a, stack_b, all, ft_lstmax_num(stack_a) + 1);
	while (all->size_b)
		pa(stack_a, stack_b, all);
}
