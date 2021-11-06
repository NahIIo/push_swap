/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:48:45 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 15:05:18 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int item)
{
	if (stack->top == stack->max_size)
		handle_error();
	stack->items[stack->top] = item;
	stack->top++;
}

void	push_inst(t_stack *dst, t_stack *src)
{
	int		elem;

	if (src->top > 0)
	{
		elem = pop(src);
		push(dst, elem);
	}
}

void	reverse_rotate(t_stack *stack)
{
	int		elem;
	t_stack	*tmp;
	int		size;

	tmp = NULL;
	if (stack->top > 1)
	{
		size = stack->top;
		tmp = initialize(size - 1);
		while (stack->top > 1)
			push_inst(tmp, stack);
		elem = pop(stack);
		while (stack->top < size - 1)
			push_inst(stack, tmp);
		push(stack, elem);
		free(tmp->items);
		free(tmp);
	}
}

void	rotate(t_stack *stack)
{
	int		elem;
	t_stack	*tmp;
	int		size;

	tmp = NULL;
	if (stack->top > 1)
	{
		size = stack->top;
		elem = pop(stack);
		tmp = initialize(size - 1);
		while (stack->top > 0)
			push_inst(tmp, stack);
		push(stack, elem);
		while (stack->top < size)
			push_inst(stack, tmp);
		free(tmp->items);
		free(tmp);
	}
}

void	swap(t_stack *stack)
{
	int		elem1;
	int		elem2;

	if (stack->top > 1)
	{
		elem1 = pop(stack);
		elem2 = pop(stack);
		push(stack, elem1);
		push(stack, elem2);
	}
}
