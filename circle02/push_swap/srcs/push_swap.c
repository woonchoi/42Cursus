/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:07:46 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 01:53:55 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (1 < argc)
	{
		init_info(&info);
		ft_parsing(argc, argv, &info);
		preprocessing(&info);
		if (!check_sorted(&info))
			ft_sort(&info);
		free_all(&info);
	}
	return (0);
}
