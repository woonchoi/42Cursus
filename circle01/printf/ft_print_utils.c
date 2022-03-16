/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:03:50 by woonchoi          #+#    #+#             */
/*   Updated: 2021/10/08 15:06:33 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_base(const char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_strlen_pf(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_itoa_pf(const char type, char *num_str,
			unsigned long long num, int base)
{
	int		printed_len;

	printed_len = 0;
	if (num == 0)
		num_str[printed_len++] = '0';
	else
	{
		while (num != 0)
		{
			num_str[printed_len++] = ft_get_base(type)[num % base];
			num = num / base;
		}
	}
	return (printed_len);
}

int	ft_print_num(long long num, const char type, int base)
{
	int		printed_len;
	int		len;
	char	num_str[17];

	printed_len = 0;
	len = ft_itoa_pf(type, num_str, num, base);
	while (len-- > 0)
		printed_len += write(1, &num_str[len], 1);
	return (printed_len);
}
