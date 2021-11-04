/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:00:47 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:00:47 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, t_all *all)
{
	int	max;

	max = ft_lstmax_num(stack_a);
	while (!is_sorted((*stack_a)))
	{
		if ((*stack_a)->num == max)
			ra(stack_a, all);
		else
			sa(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	int	min;

	min = ft_lstmin_num(stack_a);
	while ((*stack_a)->num != min)
	{
		ra(stack_a, all);
	}
	pb(stack_a, stack_b, all);
	sort_three(stack_a, all);
	pa(stack_a, stack_b, all);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	int	min;

	min = ft_lstmin_num(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)-> num == min)
		{
			pb(stack_a, stack_b, all);
			break ;
		}
		ra(stack_a, all);
	}
	min = ft_lstmin_num(stack_a);
	while ((*stack_a))
	{
		if ((*stack_a)-> num == min)
		{
			pb(stack_a, stack_b, all);
			break ;
		}
		ra(stack_a, all);
	}
	sort_three(stack_a, all);
	pa(stack_a, stack_b, all);
	pa(stack_a, stack_b, all);
}
