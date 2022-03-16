/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_image_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:16:10 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 10:16:46 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

static void	init_player_north(t_info *info)
{
	info->asset.baba[0][0][0] = ft_xpm_to_img(info, "baba_N1_1.xpm", IMG_P);
	info->asset.baba[0][0][1] = ft_xpm_to_img(info, "baba_N1_2.xpm", IMG_P);
	info->asset.baba[0][0][2] = ft_xpm_to_img(info, "baba_N1_3.xpm", IMG_P);
	info->asset.baba[0][1][0] = ft_xpm_to_img(info, "baba_N2_1.xpm", IMG_P);
	info->asset.baba[0][1][1] = ft_xpm_to_img(info, "baba_N2_2.xpm", IMG_P);
	info->asset.baba[0][1][2] = ft_xpm_to_img(info, "baba_N2_3.xpm", IMG_P);
	info->asset.baba[0][2][0] = ft_xpm_to_img(info, "baba_N3_1.xpm", IMG_P);
	info->asset.baba[0][2][1] = ft_xpm_to_img(info, "baba_N3_2.xpm", IMG_P);
	info->asset.baba[0][2][2] = ft_xpm_to_img(info, "baba_N3_3.xpm", IMG_P);
	info->asset.baba[0][3][0] = ft_xpm_to_img(info, "baba_N4_1.xpm", IMG_P);
	info->asset.baba[0][3][1] = ft_xpm_to_img(info, "baba_N4_2.xpm", IMG_P);
	info->asset.baba[0][3][2] = ft_xpm_to_img(info, "baba_N4_3.xpm", IMG_P);
}

static void	init_player_east(t_info *info)
{
	info->asset.baba[3][0][0] = ft_xpm_to_img(info, "baba_E1_1.xpm", IMG_P);
	info->asset.baba[3][0][1] = ft_xpm_to_img(info, "baba_E1_2.xpm", IMG_P);
	info->asset.baba[3][0][2] = ft_xpm_to_img(info, "baba_E1_3.xpm", IMG_P);
	info->asset.baba[3][1][0] = ft_xpm_to_img(info, "baba_E2_1.xpm", IMG_P);
	info->asset.baba[3][1][1] = ft_xpm_to_img(info, "baba_E2_2.xpm", IMG_P);
	info->asset.baba[3][1][2] = ft_xpm_to_img(info, "baba_E2_3.xpm", IMG_P);
	info->asset.baba[3][2][0] = ft_xpm_to_img(info, "baba_E3_1.xpm", IMG_P);
	info->asset.baba[3][2][1] = ft_xpm_to_img(info, "baba_E3_2.xpm", IMG_P);
	info->asset.baba[3][2][2] = ft_xpm_to_img(info, "baba_E3_3.xpm", IMG_P);
	info->asset.baba[3][3][0] = ft_xpm_to_img(info, "baba_E4_1.xpm", IMG_P);
	info->asset.baba[3][3][1] = ft_xpm_to_img(info, "baba_E4_2.xpm", IMG_P);
	info->asset.baba[3][3][2] = ft_xpm_to_img(info, "baba_E4_3.xpm", IMG_P);
}

static void	init_player_west(t_info *info)
{
	info->asset.baba[1][0][0] = ft_xpm_to_img(info, "baba_W1_1.xpm", IMG_P);
	info->asset.baba[1][0][1] = ft_xpm_to_img(info, "baba_W1_2.xpm", IMG_P);
	info->asset.baba[1][0][2] = ft_xpm_to_img(info, "baba_W1_3.xpm", IMG_P);
	info->asset.baba[1][1][0] = ft_xpm_to_img(info, "baba_W2_1.xpm", IMG_P);
	info->asset.baba[1][1][1] = ft_xpm_to_img(info, "baba_W2_2.xpm", IMG_P);
	info->asset.baba[1][1][2] = ft_xpm_to_img(info, "baba_W2_3.xpm", IMG_P);
	info->asset.baba[1][2][0] = ft_xpm_to_img(info, "baba_W3_1.xpm", IMG_P);
	info->asset.baba[1][2][1] = ft_xpm_to_img(info, "baba_W3_2.xpm", IMG_P);
	info->asset.baba[1][2][2] = ft_xpm_to_img(info, "baba_W3_3.xpm", IMG_P);
	info->asset.baba[1][3][0] = ft_xpm_to_img(info, "baba_W4_1.xpm", IMG_P);
	info->asset.baba[1][3][1] = ft_xpm_to_img(info, "baba_W4_2.xpm", IMG_P);
	info->asset.baba[1][3][2] = ft_xpm_to_img(info, "baba_W4_3.xpm", IMG_P);
}

static void	init_player_south(t_info *info)
{
	info->asset.baba[2][0][0] = ft_xpm_to_img(info, "baba_S1_1.xpm", IMG_P);
	info->asset.baba[2][0][1] = ft_xpm_to_img(info, "baba_S1_2.xpm", IMG_P);
	info->asset.baba[2][0][2] = ft_xpm_to_img(info, "baba_S1_3.xpm", IMG_P);
	info->asset.baba[2][1][0] = ft_xpm_to_img(info, "baba_S2_1.xpm", IMG_P);
	info->asset.baba[2][1][1] = ft_xpm_to_img(info, "baba_S2_2.xpm", IMG_P);
	info->asset.baba[2][1][2] = ft_xpm_to_img(info, "baba_S2_3.xpm", IMG_P);
	info->asset.baba[2][2][0] = ft_xpm_to_img(info, "baba_S3_1.xpm", IMG_P);
	info->asset.baba[2][2][1] = ft_xpm_to_img(info, "baba_S3_2.xpm", IMG_P);
	info->asset.baba[2][2][2] = ft_xpm_to_img(info, "baba_S3_3.xpm", IMG_P);
	info->asset.baba[2][3][0] = ft_xpm_to_img(info, "baba_S4_1.xpm", IMG_P);
	info->asset.baba[2][3][1] = ft_xpm_to_img(info, "baba_S4_2.xpm", IMG_P);
	info->asset.baba[2][3][2] = ft_xpm_to_img(info, "baba_S4_3.xpm", IMG_P);
	info->asset.baba_end[0][0] = ft_xpm_to_img(info, "win_0_1.xpm", IMG_D);
	info->asset.baba_end[0][1] = ft_xpm_to_img(info, "win_0_2.xpm", IMG_D);
	info->asset.baba_end[0][2] = ft_xpm_to_img(info, "win_0_3.xpm", IMG_D);
	info->asset.baba_end[1][0] = ft_xpm_to_img(info, "defeat_0_1.xpm", IMG_D);
	info->asset.baba_end[1][1] = ft_xpm_to_img(info, "defeat_0_2.xpm", IMG_D);
	info->asset.baba_end[1][2] = ft_xpm_to_img(info, "defeat_0_3.xpm", IMG_D);
	info->asset.skull[0] = ft_xpm_to_img(info, "skull_24_1.xpm", IMG_D);
	info->asset.skull[1] = ft_xpm_to_img(info, "skull_24_2.xpm", IMG_D);
	info->asset.skull[2] = ft_xpm_to_img(info, "skull_24_3.xpm", IMG_D);
}

void	init_player_image(t_info *info)
{
	init_player_north(info);
	init_player_east(info);
	init_player_west(info);
	init_player_south(info);
}
