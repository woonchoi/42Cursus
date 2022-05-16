/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:46:52 by woonchoi          #+#    #+#             */
/*   Updated: 2021/05/13 15:35:02 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len < ft_strlen(s))
		result = (char *)malloc(len + 1);
	else
		result = (char *)malloc(ft_strlen(s) + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
