/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:30:28 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 02:13:48 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(int n)
{
	if (n == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

void	ft_parsing(int argc, char **argv, t_info *info)
{
	char	**temp;
	int		i;
	int		j;
	int		num;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !is_digit(argv[i][ft_strlen(argv[i]) - 1]))
			print_error(1);
		temp = ft_split(argv[i], ' ');
		j = 0;
		while (temp[j])
		{
			num = ft_atoll(temp[j]);
			push_front(num, &info->top_a, &info->bot_a);
			info->size_a++;
			j++;
		}
		free_vec((void **)temp);
		i++;
	}
}
