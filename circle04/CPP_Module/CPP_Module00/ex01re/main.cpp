/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:39:50 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/06 14:57:24 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <unistd.h>

int	main(void)
{
	PhoneBook 	phone_book;
	std::string	mode = "";

	while (1)
	{
		system("clear");
		std::cout << "Welcome to my AWESOME PHONEBOOK" << std::endl << std::endl;
		std::cout << "Mode list" << std::endl;
		std::cout << "1. ADD" << std::endl;
		std::cout << "2. SEARCH" << std::endl;
		std::cout << "3. EXIT" << std::endl << std::endl;
		std::cout << "Enter the mode : ";
		std::getline(std::cin, mode);
		if (!mode.compare("ADD"))
		{
			system("clear");
			phone_book.inputContact();
		}
		else if (!mode.compare("SEARCH"))
		{
			system("clear");
			phone_book.searchContact();
		}
		else if (!mode.compare("EXIT"))
		{
			system("clear");
			break ;
		}
	}
	std::cout << "Exit PHONEBOOK" << std::endl;
	sleep(2);
	return (0);
}