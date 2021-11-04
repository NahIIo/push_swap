/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:00:51 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:03:30 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_step(t_stack **stack, int ref);
void	shortest_path(t_all *all, t_stack **stack, char stack_name, int ref);

void	sort_simple(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	int	min;

	while (all->size_a > 3)
	{
		min = ft_lstmin_num(stack_a);
		shortest_path(all, stack_a, 'a', min);
		pb(stack_a, stack_b, all);
		if(is_sorted((*stack_a)))
			break ;
	}
	sort_three(stack_a, all);
	while(all->size_b)
		pa(stack_a, stack_b, all);
}

int	count_step(t_stack **stack, int ref)
{
	int	step;
	t_stack	*tmp;

	tmp = *stack;
	step = 0;
		while (tmp->num != ref)
	{
		tmp = tmp->next;
		step++;
	}
	return (step);
}

void	shortest_path(t_all *all, t_stack **stack, char stack_name, int ref)
{
	int	step;

	step = count_step(stack, ref);
	if (stack_name == 'b')
	{
		if(step < (all->size_b >> 1))
			while((*stack)->num != ref)
				rb(stack, all);
		else
			while((*stack)->num != ref)
				rrb(stack, all);
	}
	else
	{
		if(step < (all->size_a >> 1))
			while((*stack)->num != ref)
				ra(stack, all);
		else
			while((*stack)->num != ref)
				rra(stack, all);
	}
}
