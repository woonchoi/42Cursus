/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:32:58 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:07:39 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	key_press_hook(int key_code, t_info *info)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_BACKSPACE || key_code == KEY_R)
		reset_game(info);
	else if (key_code == KEY_RETURN)
	{
		if (info->game.move_count == 0)
			info->game_status = TRUE;
	}
	else if (info->game_status == TRUE)
	{
		if (key_code == KEY_W || key_code == KEY_ARROW_UP)
			move_direc(info, NORTH);
		else if (key_code == KEY_A || key_code == KEY_ARROW_LEFT)
			move_direc(info, WEST);
		else if (key_code == KEY_S || key_code == KEY_ARROW_DOWN)
			move_direc(info, SOUTH);
		else if (key_code == KEY_D || key_code == KEY_ARROW_RIGHT)
			move_direc(info, EAST);
	}
	return (0);
}

int	key_release_hook(int key_code, t_info *info)
{
	if (key_code == KEY_W || key_code == KEY_ARROW_UP)
		release_key(info, NORTH);
	else if (key_code == KEY_A || key_code == KEY_ARROW_LEFT)
		release_key(info, WEST);
	else if (key_code == KEY_S || key_code == KEY_ARROW_DOWN)
		release_key(info, SOUTH);
	else if (key_code == KEY_D || key_code == KEY_ARROW_RIGHT)
		release_key(info, EAST);
	return (0);
}

int	exit_hook(t_info *info)
{
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	exit(0);
}
