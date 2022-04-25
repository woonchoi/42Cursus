/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:29:21 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:19 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(long int n)
{
	return ((n < 0) ? -n : n);
}

static int	ft_intlen(long int n)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		length;
	int		minus;
	char	*result;

	length = ft_intlen(n);
	result = (char *)malloc(length + 1);
	minus = (n < 0) ? 1 : 0;
	if (!result)
		return (0);
	result[length] = 0;
	while (length--)
	{
		result[length] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
	}
	if (minus)
		result[0] = '-';
	return (result);
}
