/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:11:36 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/11 14:18:10 by woonchoi         ###   ########.fr       */
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
		void	announce(void);
		~Zombie(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif