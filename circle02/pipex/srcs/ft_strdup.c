/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:52:36 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/06 23:29:35 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*dest_cur;

	dest = (char *)malloc(ft_strlen(s) + 1);
	if (!dest)
		return (0);
	dest_cur = dest;
	while (*s)
		*dest_cur++ = *s++;
	*dest_cur = 0;
	return (dest);
}
