/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:06:43 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/24 16:22:37 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_wall_one(t_info *info)
{
	info->asset.wall[0][0] = ft_xpm_to_img(info, "wall_0_1.xpm", IMG_W);
	info->asset.wall[0][1] = ft_xpm_to_img(info, "wall_0_2.xpm", IMG_W);
	info->asset.wall[0][2] = ft_xpm_to_img(info, "wall_0_3.xpm", IMG_W);
	info->asset.wall[1][0] = ft_xpm_to_img(info, "wall_1_1.xpm", IMG_W);
	info->asset.wall[1][1] = ft_xpm_to_img(info, "wall_1_2.xpm", IMG_W);
	info->asset.wall[1][2] = ft_xpm_to_img(info, "wall_1_3.xpm", IMG_W);
	info->asset.wall[2][0] = ft_xpm_to_img(info, "wall_2_1.xpm", IMG_W);
	info->asset.wall[2][1] = ft_xpm_to_img(info, "wall_2_2.xpm", IMG_W);
	info->asset.wall[2][2] = ft_xpm_to_img(info, "wall_2_3.xpm", IMG_W);
	info->asset.wall[3][0] = ft_xpm_to_img(info, "wall_3_1.xpm", IMG_W);
	info->asset.wall[3][1] = ft_xpm_to_img(info, "wall_3_2.xpm", IMG_W);
	info->asset.wall[3][2] = ft_xpm_to_img(info, "wall_3_3.xpm", IMG_W);
}

static void	init_wall_two(t_info *info)
{
	info->asset.wall[4][0] = ft_xpm_to_img(info, "wall_4_1.xpm", IMG_W);
	info->asset.wall[4][1] = ft_xpm_to_img(info, "wall_4_2.xpm", IMG_W);
	info->asset.wall[4][2] = ft_xpm_to_img(info, "wall_4_3.xpm", IMG_W);
	info->asset.wall[5][0] = ft_xpm_to_img(info, "wall_5_1.xpm", IMG_W);
	info->asset.wall[5][1] = ft_xpm_to_img(info, "wall_5_2.xpm", IMG_W);
	info->asset.wall[5][2] = ft_xpm_to_img(info, "wall_5_3.xpm", IMG_W);
	info->asset.wall[6][0] = ft_xpm_to_img(info, "wall_6_1.xpm", IMG_W);
	info->asset.wall[6][1] = ft_xpm_to_img(info, "wall_6_2.xpm", IMG_W);
	info->asset.wall[6][2] = ft_xpm_to_img(info, "wall_6_3.xpm", IMG_W);
	info->asset.wall[7][0] = ft_xpm_to_img(info, "wall_7_1.xpm", IMG_W);
	info->asset.wall[7][1] = ft_xpm_to_img(info, "wall_7_2.xpm", IMG_W);
	info->asset.wall[7][2] = ft_xpm_to_img(info, "wall_7_3.xpm", IMG_W);
}

static void	init_wall_three(t_info *info)
{
	info->asset.wall[8][0] = ft_xpm_to_img(info, "wall_8_1.xpm", IMG_W);
	info->asset.wall[8][1] = ft_xpm_to_img(info, "wall_8_2.xpm", IMG_W);
	info->asset.wall[8][2] = ft_xpm_to_img(info, "wall_8_3.xpm", IMG_W);
	info->asset.wall[9][0] = ft_xpm_to_img(info, "wall_9_1.xpm", IMG_W);
	info->asset.wall[9][1] = ft_xpm_to_img(info, "wall_9_2.xpm", IMG_W);
	info->asset.wall[9][2] = ft_xpm_to_img(info, "wall_9_3.xpm", IMG_W);
	info->asset.wall[10][0] = ft_xpm_to_img(info, "wall_10_1.xpm", IMG_W);
	info->asset.wall[10][1] = ft_xpm_to_img(info, "wall_10_2.xpm", IMG_W);
	info->asset.wall[10][2] = ft_xpm_to_img(info, "wall_10_3.xpm", IMG_W);
	info->asset.wall[11][0] = ft_xpm_to_img(info, "wall_11_1.xpm", IMG_W);
	info->asset.wall[11][1] = ft_xpm_to_img(info, "wall_11_2.xpm", IMG_W);
	info->asset.wall[11][2] = ft_xpm_to_img(info, "wall_11_3.xpm", IMG_W);
}

static void	init_wall_four(t_info *info)
{
	info->asset.wall[12][0] = ft_xpm_to_img(info, "wall_12_1.xpm", IMG_W);
	info->asset.wall[12][1] = ft_xpm_to_img(info, "wall_12_2.xpm", IMG_W);
	info->asset.wall[12][2] = ft_xpm_to_img(info, "wall_12_3.xpm", IMG_W);
	info->asset.wall[13][0] = ft_xpm_to_img(info, "wall_13_1.xpm", IMG_W);
	info->asset.wall[13][1] = ft_xpm_to_img(info, "wall_13_2.xpm", IMG_W);
	info->asset.wall[13][2] = ft_xpm_to_img(info, "wall_13_3.xpm", IMG_W);
	info->asset.wall[14][0] = ft_xpm_to_img(info, "wall_14_1.xpm", IMG_W);
	info->asset.wall[14][1] = ft_xpm_to_img(info, "wall_14_2.xpm", IMG_W);
	info->asset.wall[14][2] = ft_xpm_to_img(info, "wall_14_3.xpm", IMG_W);
	info->asset.wall[15][0] = ft_xpm_to_img(info, "wall_15_1.xpm", IMG_W);
	info->asset.wall[15][1] = ft_xpm_to_img(info, "wall_15_2.xpm", IMG_W);
	info->asset.wall[15][2] = ft_xpm_to_img(info, "wall_15_3.xpm", IMG_W);
}

void	init_wall_image(t_info *info)
{
	init_wall_one(info);
	init_wall_two(info);
	init_wall_three(info);
	init_wall_four(info);
}
