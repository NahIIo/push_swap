/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:59 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:00:00 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc == 1)
		return (0);
	all.stack_a = NULL;
	all.stack_b = NULL;
	all.size_a = argc - 1;
	all.size_b = 0;
	all.stack_a = parse_arguments(argc, argv, &all);
	sort_stack(&(all.stack_a), &(all.stack_b), &all);
	ft_lstfree((t_list **)&(all.stack_a));
	ft_lstfree((t_list **)&(all.stack_b));
	return (0);
}
