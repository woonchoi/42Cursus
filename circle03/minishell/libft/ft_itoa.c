/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:29:21 by woonchoi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/05 15:58:11 by woonchoi         ###   ########.fr       */
=======
/*   Updated: 2021/05/13 15:30:19 by woonchoi         ###   ########.fr       */
>>>>>>> bdd76eec843f4ecb89de5f522d89a628ea152833
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(long int n)
{
<<<<<<< HEAD
	if (n < 0)
		return (-n);
	else
		return (n);
=======
	return ((n < 0) ? -n : n);
>>>>>>> bdd76eec843f4ecb89de5f522d89a628ea152833
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

<<<<<<< HEAD
char	*ft_itoa(int n)
=======
char		*ft_itoa(int n)
>>>>>>> bdd76eec843f4ecb89de5f522d89a628ea152833
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
