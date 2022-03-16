/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:28:41 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 16:22:08 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers_bonus.h"

static int	ft_isspace(char c)
{
	return ((9 <= c && c <= 13) || c == ' ');
}

static int	ft_isdigit(char c)
{
	return (('0' <= c && c <= '9'));
}

static void	check_input(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		print_err("arguments error\n");
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str)
		print_err("arguments error\n");
}

int	ft_atoi(const char *str)
{
	long long	result;

	result = 0;
	check_input(str);
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result > 2147483647)
			print_err("arguments error\n");
		str++;
	}
	return (result);
}
