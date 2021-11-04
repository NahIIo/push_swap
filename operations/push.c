/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:24 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 09:59:25 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*new;

	new = (*stack2);
	(*stack2) = (*stack2)->next;
	if (*stack2)
		(*stack2)->prev = NULL;
	new->next = NULL;
	llst_add_to_front(stack1, new);
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	if (all->size_b > 0)
	{
		push(stack_a, stack_b);
		write(1, "pa\n", 3);
		all->size_a++;
		all->size_b--;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	if (all->size_a > 0)
	{
		push(stack_b, stack_a);
		write(1, "pb\n", 3);
		all->size_a--;
		all->size_b++;
	}
}
