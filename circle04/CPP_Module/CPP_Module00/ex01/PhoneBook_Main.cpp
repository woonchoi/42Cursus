/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_Main.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:23:54 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/05 14:21:58 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

int main(void)
{
	std::string	command;
	Phonebook	phonebook;
	int			index;

	index = 0;
	while (!std::cin.eof())
	{
		std::cout << "Enter a command (SEARCH | ADD | EXIT)" << std::endl;
		std::cout << ">";
		std::getline(std::cin, command);
		if (!command.compare("EXIT"))
			return (0);
		else if (!command.compare("ADD"))
		{
			Contact phonenum
			phonebook.add_contact();
		}
	}
}

