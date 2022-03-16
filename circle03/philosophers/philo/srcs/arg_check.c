/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:25:06 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/09 15:31:10 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_input(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		return (FALSE);
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}

static int	check_arg(int argc, char **argv, int *ret)
{
	int	temp;

	if (argc == 6)
	{
		ft_atoi(argv[5], &temp);
		if (temp == 0)
			return (0);
		*ret = temp;
		return (1);
	}
	*ret = 0;
	return (1);
}

static int	arg_validate(t_info *info)
{
	if (info->philo_num < 1 || info->philo_num > 200)
		return (print_err("philo_num is out of range\n"));
	if (info->time_to_die == 0 || info->time_to_eat == 0
		|| info->time_to_sleep == 0)
		return (print_err("time can't be zero\n"));
	return (TRUE);
}

int	arg_check(t_table *table, int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (print_err("The number of parameters is insufficient\n"));
	i = 0;
	while (++i < argc)
	{
		if (!check_input(argv[i]))
			return (print_err("Input must be a valid positive integer\n"));
	}
	if (!ft_atoi(argv[1], &(table->info.philo_num))
		|| !ft_atoi(argv[2], &(table->info.time_to_die))
		|| !ft_atoi(argv[3], &(table->info.time_to_eat))
		|| !ft_atoi(argv[4], &(table->info.time_to_sleep))
		|| !check_arg(argc, argv, &(table->info.must_eat_count)))
		return (print_err("An invalid number has been entered\n"));
	table->info.eat_finish = 0;
	table->info.finish = 0;
	table->info.err = 0;
	return (arg_validate(&table->info));
}
