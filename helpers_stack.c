/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:55 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 09:59:56 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_has(t_stack **stack, int chunk_max)
{
	t_stack	*s;

	s = (*stack);
	while (s)
	{
		if (s->num <= chunk_max)
			return (1);
		s = s->next;
	}
	return (0);
}

int	is_sorted(t_stack *s)
{
	t_stack	*head;
	int		cut;

	cut = 0;
	head = s;
	while (s && s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	if (s && head)
	{
		if (s->num < head->num)
			return (0);
	}
	return (1);
}

int	is_rev_sorted(t_stack *s)
{
	t_stack	*head;
	int		cut;

	cut = 0;
	head = s;
	while (s && s->next)
	{
		if (s->num < s->next->num)
			return (0);
		s = s->next;
	}
	if (s && head)
	{
		if (s->num > head->num)
			return (0);
	}
	return (1);
}
