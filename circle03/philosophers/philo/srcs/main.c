/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:26:06 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 16:14:34 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!arg_check(&table, argc, argv))
		return (-1);
	if (!init_all(&table))
	{
		free_all(&table);
		return (-1);
	}
	philosophers(&table);
	return (0);
}
