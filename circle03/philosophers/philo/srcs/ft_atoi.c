/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:24:03 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 15:42:05 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

int	ft_isdigit(char c)
{
	return (('0' <= c && c <= '9'));
}

int	ft_atoi(const char *str, int *ret)
{
	long long	result;

	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > 2147483647)
			return (FALSE);
		str++;
	}
	*ret = (int)result;
	return (TRUE);
}
