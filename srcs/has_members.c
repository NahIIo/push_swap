/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_members.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:49:12 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 15:05:24 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stacks(t_stack *b, t_stack *a, int items[2],
		int places[2])
{
	while (places[0] <= (b->top - 1) / 2 && b->items[b->top - 1] != items[0]
		&& places[1] <= (a->top - 1) / 2 && a->items[0] != items[1])
	{
		reverse_rotate(b);
		reverse_rotate(a);
		write(1, "rrr\n", 5);
	}
	while (places[0] <= (b->top - 1) / 2 && b->items[b->top - 1] != items[0])
	{
		reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	while (places[1] <= (a->top - 1) / 2 && a->items[0] != items[1])
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
}

void	rotate_stacks(t_stack *b, t_stack *a, int items[2], int places[2])
{
	while (places[0] > (b->top - 1) / 2 && b->items[b->top - 1] != items[0]
		&& places[1] > (a->top - 1) / 2 && a->items[0] != items[1])
	{
		rotate(b);
		rotate(a);
		write(1, "rr\n", 3);
	}
	while (places[0] > (b->top - 1) / 2 && b->items[b->top - 1] != items[0])
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	while (places[1] > (a->top - 1) / 2 && a->items[0] != items[1])
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

int	get_mvs_2(int stuff[2], t_stack *a, t_stack *b, int member)
{
	int		mvs_a;

	if (stuff[1] > (a->top - 1) / 2)
		mvs_a = a->top - stuff[1];
	else
		mvs_a = stuff[1];
	if ((member > (b->top - 1) / 2 && stuff[1] > (a->top - 1) / 2)
		|| (member <= (b->top - 1) / 2 && stuff[1] <= (a->top - 1) / 2))
	{
		if (stuff[0] < mvs_a)
			stuff[0] = mvs_a;
	}
	else
		stuff[0] += mvs_a;
	return (stuff[0]);
}

int	get_mvs(t_stack *b, t_stack *a, int limits[2], int member)
{
	int		stuff[2];

	if (member > (b->top - 1) / 2)
		stuff[0] = b->top - member;
	else
		stuff[0] = member + 2;
	stuff[1] = a->top - 1;
	while (b->items[member] > limits[0] && b->items[member] < limits[1]
		&& stuff[1] > 0 && (b->items[member] < a->items[stuff[1]]
			|| b->items[member] > a->items[stuff[1] - 1]))
		stuff[1]--;
	while ((b->items[member] < limits[0] || b->items[member] > limits[1])
		&& stuff[1] >= 0 && a->items[stuff[1]] != limits[1])
		stuff[1]--;
	return (get_mvs_2(stuff, a, b, member));
}

int	has_members(t_stack *stack, int *group)
{
	int		i;

	i = stack->top;
	while (--i >= 0)
	{
		if (stack->items[i] >= group[0] && stack->items[i] <= group[1])
			return (1);
	}
	return (0);
}
