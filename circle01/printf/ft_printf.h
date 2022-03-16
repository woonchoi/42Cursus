/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:07:10 by woonchoi          #+#    #+#             */
/*   Updated: 2021/10/08 14:19:40 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

char	*ft_get_base(const char type);
int		ft_strlen_pf(char *str);
int		ft_itoa_pf(const char type, char *num_str,
			unsigned long long num, int base);
int		ft_print_num(long long num, const char type, int base);

int		ft_print_memory(va_list ap, const char type);
int		ft_print_int(va_list ap, const char type);
int		ft_print_unsigned_int(va_list ap, const char type);
int		ft_print_hexadecimal(va_list ap, const char type);
int		ft_print_char(va_list ap);
int		ft_print_string(va_list ap);

int		ft_parse_type(const char type, va_list ap);
int		ft_parse_format(const char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif