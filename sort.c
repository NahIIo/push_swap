/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:00:55 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:03:35 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	if (is_sorted(*stack_a))
		return ;
	else if (all->size_a == 2 && (*stack_a)->num < (*stack_a)->next->num)
		return ;
	else if (all->size_a == 2 && (*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
	else if (all->size_a == 3)
		sort_three(stack_a, all);
	else if (all->size_a == 4)
		sort_four(stack_a, stack_b, all);
	else if (all->size_a == 5)
		sort_five(stack_a, stack_b, all);
	else if (all->size_a <= 20)
		sort_simple(stack_a, stack_b, all);
	else
		insertion_sort(stack_a, stack_b, all);
}
