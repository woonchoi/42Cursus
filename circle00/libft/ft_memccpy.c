/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:02:15 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:30 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_cur;
	unsigned char	*src_cur;
	unsigned char	end;

	dst_cur = dst;
	src_cur = (unsigned char *)src;
	end = c;
	while (n--)
	{
		*dst_cur++ = *src_cur++;
		if (*(src_cur - 1) == end)
			return (dst_cur);
	}
	return (0);
}
