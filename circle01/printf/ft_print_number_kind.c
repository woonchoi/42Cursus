/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_kind.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:10:39 by woonchoi          #+#    #+#             */
/*   Updated: 2021/10/08 14:15:08 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(va_list ap, const char type)
{
	int			printed_len;
	long long	num;

	printed_len = 0;
	num = (unsigned long long)va_arg(ap, void *);
	printed_len += write(1, "0x", 2);
	printed_len += ft_print_num(num, type, 16);
	return (printed_len);
}

int	ft_print_int(va_list ap, const char type)
{
	int			printed_len;
	long long	num;

	printed_len = 0;
	num = va_arg(ap, int);
	if (num < 0)
	{
		num = -num;
		printed_len += write(1, "-", 1);
	}
	printed_len += ft_print_num(num, type, 10);
	return (printed_len);
}

int	ft_print_unsigned_int(va_list ap, const char type)
{
	int			printed_len;
	long long	num;

	num = va_arg(ap, unsigned int);
	printed_len = ft_print_num(num, type, 10);
	return (printed_len);
}

int	ft_print_hexadecimal(va_list ap, const char type)
{
	int			printed_len;
	long long	num;

	num = va_arg(ap, unsigned int);
	printed_len = ft_print_num(num, type, 16);
	return (printed_len);
}
