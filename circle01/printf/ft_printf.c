/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:34:42 by woonchoi          #+#    #+#             */
/*   Updated: 2021/10/08 13:19:33 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_type(const char type, va_list ap)
{
	int		printed_len;

	printed_len = 0;
	if (type == 'c')
		printed_len += ft_print_char(ap);
	else if (type == 's')
		printed_len += ft_print_string(ap);
	else if (type == 'p')
		printed_len += ft_print_memory(ap, type);
	else if (type == 'd' || type == 'i')
		printed_len += ft_print_int(ap, type);
	else if (type == 'u')
		printed_len += ft_print_unsigned_int(ap, type);
	else if (type == 'x' || type == 'X')
		printed_len += ft_print_hexadecimal(ap, type);
	else if (type == '%')
		printed_len += write(1, "%", 1);
	return (printed_len);
}

int	ft_parse_format(const char *format, va_list ap)
{
	int		printed_len;

	printed_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_len += ft_parse_type(*format, ap);
		}
		else
			printed_len += write(1, format, 1);
		format++;
	}
	return (printed_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_len;

	va_start(ap, format);
	printed_len = ft_parse_format(format, ap);
	va_end(ap);
	return (printed_len);
}
