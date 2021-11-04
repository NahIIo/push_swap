/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:46 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:05:54 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	llst_add_to_front(t_stack **head, t_stack *new)
{
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
}

t_stack	*ft_lst_new_node(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_lstmin_num(t_stack **stack)
{
	int		tmp_min;
	t_stack	*tmp;

	tmp = *stack;
	tmp_min = 0;
	if (tmp)
		tmp_min = tmp->num;
	while (tmp)
	{
		if (tmp->num < tmp_min)
			tmp_min = tmp->num;
		tmp = tmp->next;
	}
	return (tmp_min);
}

int	ft_lstmax_num(t_stack **stack)
{
	int		tmp_max;
	t_stack	*tmp;

	tmp = *stack;
	tmp_max = 0;
	if (tmp)
		tmp_max = tmp->num;
	while (tmp)
	{
		if (tmp->num > tmp_max)
			tmp_max = tmp->num;
		tmp = tmp->next;
	}
	return (tmp_max);
}
