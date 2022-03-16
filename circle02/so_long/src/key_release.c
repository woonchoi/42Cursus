/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:36:29 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/23 17:47:33 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	release_key(t_info *info, int direc)
{
	if (info->frame.direc == direc)
	{
		info->frame.move_status = FALSE;
		info->frame.direc = -1;
		info->frame.offset = 0;
	}
}
