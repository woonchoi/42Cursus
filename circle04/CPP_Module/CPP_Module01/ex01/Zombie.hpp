/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:36 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/11 14:36:07 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

	private:
		std::string	name;

	public:
		Zombie(std::string name);
		Zombie(void);
		void	announce(void);
		void	setZombieName(std::string name);
		~Zombie(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif