/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:29 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 09:59:30 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	rev_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	last = (t_stack *)ft_lstlast((t_list *)(*head));
	first = last;
	last->prev->next = NULL;
	last->next = NULL;
	first->prev = NULL;
	first->next = (*head);
	(*head)->prev = first;
	(*head) = first;
}

void	rra(t_stack **stack_a, t_all *all)
{
	if (all->size_a > 1)
	{
		rev_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b, t_all *all)
{
	if (all->size_b > 1)
	{
		rev_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	if (all->size_b > 1 && all->size_a > 1)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
