/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:33 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 09:59:34 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	rotate(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = (*head)->next;
	tmp->prev = NULL;
	last = (t_stack *)ft_lstlast((t_list *)(*head));
	last->next = (*head);
	(*head)->prev = last;
	(*head)->next = NULL;
	(*head) = tmp;
}

void	ra(t_stack **stack_a, t_all *all)
{
	if (all->size_a > 1)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b, t_all *all)
{
	if (all->size_b > 1)
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	if (all->size_b > 1 && all->size_a > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
