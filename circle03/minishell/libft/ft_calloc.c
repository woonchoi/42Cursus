/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:26:20 by woonchoi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/05 15:56:02 by woonchoi         ###   ########.fr       */
=======
/*   Updated: 2021/05/13 15:30:06 by woonchoi         ###   ########.fr       */
>>>>>>> bdd76eec843f4ecb89de5f522d89a628ea152833
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;

<<<<<<< HEAD
	dest = (char *)malloc(count * size);
=======
	dest = (char*)malloc(count * size);
>>>>>>> bdd76eec843f4ecb89de5f522d89a628ea152833
	if (!dest)
		return (0);
	ft_bzero(dest, count * size);
	return (dest);
}
