/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:11:59 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/11 14:48:18 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	Zombie	*zombie;

	if (argc != 3)
		std::cout << "The world is peaceful. (usage : ./zombieHorde [zombiecount] [name])" << std::endl;
	else
	{
		int N = std::atoi(argv[1]);
		std::string name(argv[2]);
		if (N <= 0 || N > 100)
		{
			std::cout << "Zombies range from 1 to 100" << std::endl;
			return (0);
		}
		zombie = zombieHorde(N, name);
		delete[] zombie;
	}
	return (0);
}
