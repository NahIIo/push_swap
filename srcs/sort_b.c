/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:48:50 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 15:05:19 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_many_nbrs(t_stack *a, t_stack *b)
{
	int		**groups;
	int		amount;
	int		i;

	if (a->top < 75)
		amount = 1;
	else if (a->top < 100)
		amount = 2;
	else
		amount = 3;
	groups = get_groups(a, amount);
	i = 1;
	while (i <= groups[0][0])
		push_group(a, b, groups[i++]);
	i = groups[0][0];
	while (i > 0)
	{
		push_and_sort_group(b, a, groups[i]);
		free(groups[i--]);
	}
	free(groups[i]);
	free(groups);
	sort_a(a);
}

static void	rotate_stack(t_stack *b, int item, int place)
{
	while (place > (b->top - 1) / 2 && b->items[0] != item)
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	while (place <= (b->top - 1) / 2 && b->items[0] != item)
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
}

static void	push_and_sort(t_stack *a, t_stack *b)
{
	int		place;
	int		smallest;
	int		biggest;

	if (b->top > 1)
	{
		smallest = get_smallest(b);
		biggest = get_biggest(b);
		place = b->top - 1;
		while (a->items[a->top - 1] > smallest && a->items[a->top - 1] < biggest
			&& place > 0 && (a->items[a->top - 1] > b->items[place]
				|| a->items[a->top - 1] < b->items[place - 1]))
			place--;
		while ((a->items[a->top - 1] < smallest
				|| a->items[a->top - 1] > biggest) && place >= 0
			&& b->items[place] != smallest)
			place--;
		rotate_stack(b, b->items[place], place);
	}
	push_inst(b, a);
	write(1, "pb\n", 3);
}

void	put_smallest_to_top(t_stack *a, t_stack *b)
{
	if (a->items[a->top - 1] < a->items[a->top - 2]
		&& a->items[a->top - 1] < a->items[0])
		push_and_sort(a, b);
	else if (a->items[a->top - 2] < a->items[a->top - 1]
		&& a->items[a->top - 2] <= a->items[0])
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	else if (a->items[0] < a->items[a->top - 1]
		&& a->items[0] < a->items[a->top - 2])
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	sort_b(t_stack *b)
{
	int		place;
	int		biggest;

	if (b->top > 1)
	{
		biggest = get_biggest(b);
		place = b->top - 1;
		while (place >= 0 && b->items[place] != biggest)
			place--;
		while (place > (b->top - 1) / 2 && b->items[b->top - 1] != biggest)
		{
			rotate(b);
			write(1, "rb\n", 3);
		}
		while (place <= (b->top - 1) / 2 && b->items[b->top - 1] != biggest)
		{
			reverse_rotate(b);
			write(1, "rrb\n", 4);
		}
	}
}
