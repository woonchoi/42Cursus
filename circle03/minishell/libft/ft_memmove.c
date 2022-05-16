/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:06:34 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:34 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cur;
	unsigned char	*src_cur;

	if (dst == src)
		return (dst);
	if (src < dst)
	{
		dst_cur = dst + len - 1;
		src_cur = (unsigned char *)src + len - 1;
		while (len--)
			*(dst_cur--) = *(src_cur--);
	}
	else
	{
		dst_cur = dst;
		src_cur = (unsigned char *)src;
		while (len--)
			*(dst_cur++) = *(src_cur++);
	}
	return (dst);
}
