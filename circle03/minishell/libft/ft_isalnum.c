/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 18:02:06 by woonchoi          #+#    #+#             */
/*   Updated: 2022/05/05 15:56:15 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (('0' <= c && c <= '9')
		|| ('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z'));
}
