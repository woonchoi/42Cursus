/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:29:46 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:51 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	check;
	size_t	len;

	len = ft_strlen(s) + 1;
	check = c;
	while (len--)
	{
		if (*s == check)
			return ((char *)s);
		s++;
	}
	return (0);
}
