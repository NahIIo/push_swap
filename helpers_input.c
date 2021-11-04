/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Julian <Julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:59:00 by Julian            #+#    #+#             */
/*   Updated: 2021/11/04 09:59:02 by Julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}

static	void	sign_check(const char *str, int	*sign, int *i)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		*sign = 1;
		(*i)++;
	}
}

int	push_swap_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = skip_whitespace(str);
	sign_check(str, &sign, &i);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			ft_exit_basic("");
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (sign * res > 2147483647 || sign * res < -2147483648
		|| (sign == -1 && res == 0))
		ft_exit_basic("");
	return (sign * res);
}
