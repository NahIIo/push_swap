/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:48:54 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 11:48:55 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_biggest(t_stack *stack)
{
	int		biggest;
	int		i;

	i = stack->top - 1;
	biggest = stack->items[i];
	while (--i >= 0)
	{
		if (stack->items[i] > biggest)
			biggest = stack->items[i];
	}
	return (biggest);
}

int	get_smallest(t_stack *stack)
{
	int		smallest;
	int		i;

	i = stack->top - 1;
	smallest = stack->items[i];
	while (--i >= 0)
	{
		if (stack->items[i] < smallest)
			smallest = stack->items[i];
	}
	return (smallest);
}

void	sort_a(t_stack *a)
{
	int		place;
	int		smallest;

	if (a->top > 1)
	{
		smallest = get_smallest(a);
		place = a->top - 1;
		while (place >= 0 && a->items[place] != smallest)
			place--;
		while (place > (a->top - 1) / 2 && a->items[a->top - 1] != smallest)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		while (place <= (a->top - 1) / 2 && a->items[a->top - 1] != smallest)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
	}
}
