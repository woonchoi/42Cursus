/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:47:23 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:54:21 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	ft_free_split(char **result)
{
	int		i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
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

static void	ft_split_input(char const *s, char c, size_t count, char **result)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < count)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*(s + len) && *(s + len) != c)
			len++;
		result[i++] = ft_strndup(s, len);
		if (!(result[i - 1]))
		{
			ft_free_split(result);
			result = 0;
			return ;
		}
		s = s + len + 1;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**result;

	count = ft_count_word(s, c);
	result = ft_calloc(count + 1, sizeof(char *));
	if (!(result) || !s)
		return (0);
	ft_split_input(s, c, count, result);
	return (result);
}
