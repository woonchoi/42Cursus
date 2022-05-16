/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:46:56 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:31:43 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dest;
	char	*dest_cur;

	if (n < ft_strlen(s))
		dest = (char *)malloc(n + 1);
	else
		dest = (char *)malloc(ft_strlen(s) + 1);
	if (!dest)
		return (0);
	dest_cur = dest;
	while (n-- && *s)
		*dest_cur++ = *s++;
	*dest_cur = 0;
	return (dest);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		length;
	char	*result;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	length = ft_strlen(s1);
	i = length - 1;
	while (i > 0 && ft_isinset(s1[i], set) && length)
	{
		length--;
		i--;
	}
	i = 0;
	while (ft_isinset(s1[i], set) && length)
	{
		length--;
		i++;
	}
	result = ft_strndup(s1 + i, length);
	return (result);
}
