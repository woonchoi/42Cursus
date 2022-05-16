/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:05:59 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:31:37 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;

	if (!*s2)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len < s2_len || n < s2_len)
		return (0);
	while (n >= s2_len && s1_len >= s2_len)
	{
		if (!ft_memcmp(s1, s2, s2_len))
			return ((char *)s1);
		s1++;
		n--;
		s1_len--;
	}
	return (0);
}
