/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:50:23 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:33 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_cur;
	unsigned char	*src_cur;

	if (!dst && !src)
		return (0);
	dst_cur = dst;
	src_cur = (unsigned char *)src;
	while (n--)
		*dst_cur++ = *src_cur++;
	return (dst);
}
