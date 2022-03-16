/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:16:06 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:31 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cur;
	unsigned char	end;

	s_cur = (unsigned char *)s;
	end = c;
	while (n--)
	{
		if (*(s_cur) == end)
			return (s_cur);
		s_cur++;
	}
	return (0);
}
