/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:31:15 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 02:11:32 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checker_instruction(char *cmd, t_info *info)
{
	if (!ft_strncmp(cmd, "sa\n", 4))
		sa(info, FALSE);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		sb(info, FALSE);
	else if (!ft_strncmp(cmd, "ss\n", 4))
		ss(info, FALSE);
	else if (!ft_strncmp(cmd, "pa\n", 4))
		pa(info, FALSE);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		pb(info, FALSE);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		ra(info, FALSE);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		rb(info, FALSE);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		rr(info, FALSE);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		rra(info, FALSE);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		rrb(info, FALSE);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		rrr(info, FALSE);
	else
		return (1);
	return (0);
}

void	checker(t_info *info)
{
	char	*cmd;
	int		error;

	error = 0;
	while (TRUE)
	{
		cmd = get_next_line(STDIN);
		if (cmd == NULL)
			break ;
		error |= checker_instruction(cmd, info);
		free_ptr(cmd);
	}
	if (error)
		print_error(1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (1 < argc)
	{
		init_info(&info);
		ft_parsing(argc, argv, &info);
		preprocessing(&info);
		checker(&info);
		if (check_sorted(&info))
			ft_putendl_fd("OK", STDOUT);
		else
			ft_putendl_fd("KO", STDOUT);
		free_all(&info);
	}
}
