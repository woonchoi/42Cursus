/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:53:39 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:13:35 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# define IMG_P "./img/player/"
# define IMG_W "./img/wall/"
# define IMG_D "./img/"
# define IMG_C "./img/count/"

typedef struct s_myimg
{
	void	*p;
	int		*data;
	int		w;
	int		h;
}	t_myimg;

typedef struct s_asset
{
	void	*wall[16][3];
	void	*baba[4][4][3];
	void	*floor;
	void	*star[3];
	void	*flag[3];
	void	*move;
	void	*number[10][3];
	void	*count;
	void	*baba_end[3];
	int		**wall_type;
}	t_asset;

#endif
