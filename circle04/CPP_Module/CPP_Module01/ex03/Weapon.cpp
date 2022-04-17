/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:12:53 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/13 17:17:44 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	this->weapon = "Nothing";
}

Weapon::Weapon(std::string name)
{
	this->weapon = "name";
}

void	Weapon::setType(std::string name)
{
	this->weapon = name;
}

std::string	Weapon::getType(void)
{
	return (this->weapon);
}

Weapon::~Weapon(void)
{
	
}