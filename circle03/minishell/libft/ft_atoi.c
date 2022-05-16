/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:28:52 by woonchoi          #+#    #+#             */
/*   Updated: 2022/05/05 15:55:30 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

int	ft_atoi(const char *str)
{
	long long	result;
	long long	result_prev;
	long long	sign;

	result = 0;
	result_prev = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		if (result_prev > result && sign == 1)
			return (-1);
		else if (result_prev > result && sign == -1)
			return (0);
		str++;
		result_prev = result;
	}
	return (result * sign);
}
