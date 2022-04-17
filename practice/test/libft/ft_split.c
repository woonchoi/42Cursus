/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:47:23 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:30:48 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		else if (str[i])
			i++;
	}
	return (count);
}

static char		**ft_free_split(char **result)
{
	int		i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

static char		*ft_strndup(const char *s, size_t n)
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

char			**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;
	char	**result;

	if (!s)
		return (0);
	count = ft_count_word(s, c);
	if (!(result = ft_calloc(count + 1, sizeof(char *))))
		return (0);
	len = 0;
	i = 0;
	while (i < count)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*(s + len) && *(s + len) != c)
			len++;
		if (!(result[i++] = ft_strndup(s, len)))
			return (ft_free_split(result));
		s = s + len + 1;
	}
	return (result);
}
