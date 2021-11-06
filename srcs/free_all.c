/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:18:43 by Julian            #+#    #+#             */
/*   Updated: 2021/11/06 15:27:51 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
		if (!is_sorted(a, b))
		{
			if (a->top < 20)
				sort_few_nbrs(a, b);
			else
				sort_many_nbrs(a, b);
		}
}

void	free_all(t_stack *a, t_stack *b, char **nbrs)
{
	int i;

	i = 0;
	free(a->items);
	free(a);
	free(b->items);
	free(b);
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}
