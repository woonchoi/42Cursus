/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_count_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:30:31 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 10:25:20 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_number_one(t_info *info)
{
	info->asset.number[0][0] = ft_xpm_to_img(info, "text_0_1.xpm", IMG_C);
	info->asset.number[0][1] = ft_xpm_to_img(info, "text_0_2.xpm", IMG_C);
	info->asset.number[0][2] = ft_xpm_to_img(info, "text_0_3.xpm", IMG_C);
	info->asset.number[1][0] = ft_xpm_to_img(info, "text_1_1.xpm", IMG_C);
	info->asset.number[1][1] = ft_xpm_to_img(info, "text_1_2.xpm", IMG_C);
	info->asset.number[1][2] = ft_xpm_to_img(info, "text_1_3.xpm", IMG_C);
	info->asset.number[2][0] = ft_xpm_to_img(info, "text_2_1.xpm", IMG_C);
	info->asset.number[2][1] = ft_xpm_to_img(info, "text_2_2.xpm", IMG_C);
	info->asset.number[2][2] = ft_xpm_to_img(info, "text_2_3.xpm", IMG_C);
	info->asset.number[3][0] = ft_xpm_to_img(info, "text_3_1.xpm", IMG_C);
	info->asset.number[3][1] = ft_xpm_to_img(info, "text_3_2.xpm", IMG_C);
	info->asset.number[3][2] = ft_xpm_to_img(info, "text_3_3.xpm", IMG_C);
	info->asset.number[4][0] = ft_xpm_to_img(info, "text_4_1.xpm", IMG_C);
	info->asset.number[4][1] = ft_xpm_to_img(info, "text_4_2.xpm", IMG_C);
	info->asset.number[4][2] = ft_xpm_to_img(info, "text_4_3.xpm", IMG_C);
}

static void	init_number_two(t_info *info)
{
	info->asset.number[5][0] = ft_xpm_to_img(info, "text_5_1.xpm", IMG_C);
	info->asset.number[5][1] = ft_xpm_to_img(info, "text_5_2.xpm", IMG_C);
	info->asset.number[5][2] = ft_xpm_to_img(info, "text_5_3.xpm", IMG_C);
	info->asset.number[6][0] = ft_xpm_to_img(info, "text_6_1.xpm", IMG_C);
	info->asset.number[6][1] = ft_xpm_to_img(info, "text_6_2.xpm", IMG_C);
	info->asset.number[6][2] = ft_xpm_to_img(info, "text_6_3.xpm", IMG_C);
	info->asset.number[7][0] = ft_xpm_to_img(info, "text_7_1.xpm", IMG_C);
	info->asset.number[7][1] = ft_xpm_to_img(info, "text_7_2.xpm", IMG_C);
	info->asset.number[7][2] = ft_xpm_to_img(info, "text_7_3.xpm", IMG_C);
	info->asset.number[8][0] = ft_xpm_to_img(info, "text_8_1.xpm", IMG_C);
	info->asset.number[8][1] = ft_xpm_to_img(info, "text_8_2.xpm", IMG_C);
	info->asset.number[8][2] = ft_xpm_to_img(info, "text_8_3.xpm", IMG_C);
	info->asset.number[9][0] = ft_xpm_to_img(info, "text_9_1.xpm", IMG_C);
	info->asset.number[9][1] = ft_xpm_to_img(info, "text_9_2.xpm", IMG_C);
	info->asset.number[9][2] = ft_xpm_to_img(info, "text_9_3.xpm", IMG_C);
}

void	init_count_image(t_info *info)
{
	init_number_one(info);
	init_number_two(info);
	info->asset.count = ft_xpm_to_img(info, "count.xpm", IMG_C);
}
