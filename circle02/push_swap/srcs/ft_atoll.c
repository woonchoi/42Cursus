/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:47:22 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:55:13 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoll(const char *str)
{
	long long	ret;
	long long	temp;
	int			minus;

	ret = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		ret = ret * 10 + *str - '0';
		temp = ret * minus;
		if (!is_digit(*str) || temp > INT_MAX || temp < INT_MIN)
			print_error(1);
		str++;
	}
	return ((int)temp);
}
