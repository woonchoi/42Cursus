/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:11:48 by woonchoi          #+#    #+#             */
/*   Updated: 2021/10/07 12:17:28 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(va_list ap)
{
	int		printed_len;
	char	*arg_str;

	arg_str = va_arg(ap, char *);
	if (arg_str == NULL)
		arg_str = "(null)";
	printed_len = ft_strlen_pf(arg_str);
	write(1, arg_str, printed_len);
	return (printed_len);
}
