/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:32:45 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/11 14:48:51 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zombie;
	int		i;

	if (N <= 0)
		return (NULL);
	zombie = new Zombie[N];
	for (i = 0; i < N; i++)
	{
		zombie[i].setZombieName(name);
		zombie[i].announce();
	}
	return (zombie);
}
