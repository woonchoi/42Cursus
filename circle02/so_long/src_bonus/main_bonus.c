/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:51:58 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/25 13:05:49 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

void	print_err(char *errmessage)
{
	ft_putendl_fd(errmessage, STDERR_FILENO);
	ft_putendl_fd("Error!", STDERR_FILENO);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		print_err("Usage: ./so_long [.../MAP.ber]");
	init_info(&info, argv[1]);
	mlx_do_key_autorepeatoff(info.mlx_ptr);
	mlx_hook(info.win_ptr, 2, 0, &key_press_hook, &info);
	mlx_hook(info.win_ptr, 3, 0, &key_release_hook, &info);
	mlx_hook(info.win_ptr, 17, 0, &exit_hook, &info);
	mlx_loop_hook(info.mlx_ptr, &game_loop, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
