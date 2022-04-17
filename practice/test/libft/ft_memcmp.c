/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:23:34 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:32 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_curr;
	unsigned char	*s2_curr;

	s1_curr = (unsigned char *)s1;
	s2_curr = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n--)
	{
		if (*s1_curr != *s2_curr)
			break ;
		if (n != 0)
		{
			s1_curr++;
			s2_curr++;
		}
	}
	return ((int)*s1_curr - (int)*s2_curr);
}
