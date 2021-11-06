/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_groups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:49:22 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 12:00:13 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_member_to_push2(t_stack *stack, int *group, int stuff[4])
{
	while (--stuff[0] >= 0)
	{
		if (stack->items[stuff[0]] >= group[0]
			&& stack->items[stuff[0]] <= group[1])
		{
			if (stuff[0] > (stack->top - 1) / 2)
				stuff[3] = stack->top - stuff[0];
			else
				stuff[3] = stuff[0] + 2;
			if (stuff[2] > stuff[3]
				|| (stuff[2] == stuff[3]
					&& stack->items[stuff[1]] > stack->items[stuff[0]]))
			{
				stuff[1] = stuff[0];
				stuff[2] = stuff[3];
			}
		}
	}
	return (stuff[1]);
}

static int	get_member_to_push(t_stack *stack, int *group)
{
	int		stuff[4];

	stuff[0] = stack->top - 1;
	while (stuff[0] >= 0 && (stack->items[stuff[0]] < group[0]
			|| stack->items[stuff[0]] > group[1]))
		stuff[0]--;
	stuff[1] = stuff[0];
	if (stuff[1] > (stack->top - 1) / 2)
		stuff[2] = stack->top - stuff[1];
	else
		stuff[2] = stuff[1] + 2;
	return (get_member_to_push2(stack, group, stuff));
}

void	push_group(t_stack *a, t_stack *b, int *group)
{
	int		member;
	int		place;

	while (a->top > 2 && has_members(a, group))
	{
		place = get_member_to_push(a, group);
		member = a->items[place];
		while (place > (a->top - 1) / 2 && a->items[a->top - 1] != member)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		while (place <= (a->top - 1) / 2 && a->items[a->top - 1] != member)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
		push_inst(b, a);
		write(1, "pb\n", 3);
	}
}

static void	fill_groups(int **groups, int amount, int smallest, int biggest)
{
	int		i;

	i = 1;
	if (i <= amount)
	{
		groups[i][0] = smallest;
		groups[i][1] = groups[i][0] + ((biggest - smallest) / amount);
	}
	while (++i < amount)
	{
		groups[i][0] = groups[i - 1][1] + 1;
		groups[i][1] = groups[i][0] + ((biggest - smallest) / amount);
	}
	if (i == amount)
	{
		groups[i][0] = groups[i - 1][1] + 1;
		groups[i][1] = biggest;
	}
}

int	**get_groups(t_stack *stack, int amount)
{
	int		**groups;
	int		smallest;
	int		biggest;
	int		i;

	smallest = get_smallest(stack);
	biggest = get_biggest(stack);
	groups = (int **)malloc(sizeof(int *) * (amount + 1));
	if (!(groups))
		handle_error();
	i = 0;
	groups[i] = (int *)malloc(sizeof(int));
	if (!(groups[i]))
		handle_error();
	groups[i][0] = amount;
	while (++i <= amount)
	{
		groups[i] = (int *)malloc(sizeof(int) * 2);
		if (!(groups[i]))
			handle_error();
	}
	fill_groups(groups, amount, smallest, biggest);
	return (groups);
}
