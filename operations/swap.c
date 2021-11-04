/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:39 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:07:01 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	swap(t_stack **head, int *check)
{
	t_stack	*rest;
	t_stack	*first;
	t_stack	*second;
	int		size;

	size = ft_lstsize((t_list *)(*head));
	if (size > 1)
	{
		(*check)++;
		first = (*head);
		second = first->next;
		rest = second->next;
		second->next = NULL;
		second->prev = NULL;
		first->next = rest;
		first->prev = second;
		if (rest)
			rest->prev = first;
		second->next = first;
		(*head) = second;
	}
}

void	sa(t_stack **head_a)
{
	int	check;

	check = 0;
	swap(head_a, &check);
	if (check == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **head_b)
{
	int	check;

	check = 0;
	swap(head_b, &check);
	if (check == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **head_a, t_stack **head_b)
{
	int	check;

	check = 0;
	swap(head_a, &check);
	swap(head_b, &check);
	if (check == 2)
		write(1, "ss\n", 3);
}
