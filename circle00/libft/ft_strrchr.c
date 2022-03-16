/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:47:02 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:31:41 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;
	char	check;

	check = c;
	start = (char *)s;
	while (*s)
		s++;
	while (s != start - 1)
	{
		if (*s == check)
			return ((char *)s);
		s--;
	}
	return (0);
}
