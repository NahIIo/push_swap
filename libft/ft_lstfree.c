/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:12:04 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 10:12:05 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstfree(t_list **ptr_lst)
{
	t_list	*temp;

	if (!ptr_lst || !*ptr_lst)
		return ;
	while (*ptr_lst)
	{
		temp = (*ptr_lst)->next;
		free(*ptr_lst);
		*ptr_lst = temp;
	}
	return ;
}

void	ft_lstfree_w_content(t_list **ptr_lst)
{
	t_list	*temp;

	if (!ptr_lst || !*ptr_lst)
		return ;
	while (*ptr_lst)
	{
		temp = (*ptr_lst)->next;
		free((*ptr_lst)->content);
		free(*ptr_lst);
		*ptr_lst = temp;
	}
	return ;
}
