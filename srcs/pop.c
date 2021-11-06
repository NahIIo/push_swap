/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:49:08 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 15:05:23 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *a, t_stack *b)
{
	int		item;
	int		i;

	i = a->top - 1;
	if (i > 0)
	{
		item = a->items[i--];
		while (i >= 0)
		{
			if (item > a->items[i])
				return (0);
			item = a->items[i--];
		}
	}
	if (b->top > 0)
		return (0);
	return (1);
}

int	pop(t_stack *stack)
{
	int		item;

	if (stack->top == 0)
		handle_error();
	stack->top--;
	item = stack->items[stack->top];
	return (item);
}

void	push_and_sort_group(t_stack *b, t_stack *a, int *group)
{
	int		items[2];
	int		places[2];
	int		smallest;
	int		biggest;

	while (has_members(b, group))
	{
		smallest = get_smallest(a);
		biggest = get_biggest(a);
		places[0] = get_member_to_push_and_sort(b, a, group);
		items[0] = b->items[places[0]];
		places[1] = a->top - 1;
		while (items[0] > smallest && items[0] < biggest && places[1] > 0
			&& (items[0] < a->items[places[1]]
				|| items[0] > a->items[places[1] - 1]))
			places[1]--;
		while ((items[0] < smallest || items[0] > biggest) && places[1] >= 0
			&& a->items[places[1]] != biggest)
			places[1]--;
		items[1] = a->items[places[1]];
		rotate_stacks(b, a, items, places);
		reverse_rotate_stacks(b, a, items, places);
		push_inst(a, b);
		write(1, "pa\n", 3);
	}
}

int	get_member_to_push_and_sort(t_stack *b, t_stack *a, int *group)
{
	int		member;
	int		mvs;
	int		cmp;
	int		limits[2];
	int		i;

	limits[0] = get_smallest(a);
	limits[1] = get_biggest(a);
	i = b->top - 1;
	while (i >= 0 && (b->items[i] < group[0] || b->items[i] > group[1]))
		i--;
	member = i;
	mvs = get_mvs(b, a, limits, member);
	while (--i >= 0)
	{
		cmp = get_mvs(b, a, limits, i);
		if (b->items[i] >= group[0] && b->items[i] <= group[1]
			&& (mvs > (cmp) || (mvs == cmp && b->items[member] < b->items[i])))
		{
			member = i;
			mvs = cmp;
		}
	}
	return (member);
}
