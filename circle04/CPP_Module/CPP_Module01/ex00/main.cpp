/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:11:59 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/11 14:26:27 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	int	i;

	if (argc <= 1)
	{
		std::string	name = "Zombie";
		randomChump(name);
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			std::string temp(argv[i]);
			randomChump(temp);
		}
	}
	return (0);
}
