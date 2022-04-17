/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:05:56 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/11 14:36:17 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie(void)
{
}

void	Zombie::setZombieName(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << "[" << this->name << "] " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "[" << this->name << "] " << "die" << std::endl;
}