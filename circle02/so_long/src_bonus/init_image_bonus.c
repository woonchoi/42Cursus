/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:02:07 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 15:00:52 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	*ft_xpm_to_img(t_info *info, char *file, char *img_path)
{
	char	*path;
	void	*image;

	path = ft_strjoin(img_path, file);
	image = mlx_xpm_file_to_image(info->mlx_ptr, path,
			&(info->img.w), &(info->img.h));
	free(path);
	path = 0;
	if (!image)
		print_err("Read xpm file fail");
	return (image);
}

static void	init_tile_image(t_info *info)
{
	info->asset.floor = ft_xpm_to_img(info, "floor.xpm", IMG_D);
	info->asset.star[0] = ft_xpm_to_img(info, "star_0_1.xpm", IMG_D);
	info->asset.star[1] = ft_xpm_to_img(info, "star_0_2.xpm", IMG_D);
	info->asset.star[2] = ft_xpm_to_img(info, "star_0_3.xpm", IMG_D);
	info->asset.flag[0] = ft_xpm_to_img(info, "flag_0_1.xpm", IMG_D);
	info->asset.flag[1] = ft_xpm_to_img(info, "flag_0_2.xpm", IMG_D);
	info->asset.flag[2] = ft_xpm_to_img(info, "flag_0_3.xpm", IMG_D);
}

void	init_image(t_info *info)
{
	init_player_image(info);
	init_wall_image(info);
	init_tile_image(info);
	init_count_image(info);
	init_wall_type(info);
}
