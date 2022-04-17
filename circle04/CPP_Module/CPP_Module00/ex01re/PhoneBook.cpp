/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:28:05 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/06 15:00:30 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook()
{
}

void 		PhoneBook::addContact(Contact contact)
{
	contacts[this->contact_index % 8] = contact;
	contact_index++;
}

void 		PhoneBook::inputContact()
{
	Contact contact;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "First name :";
	std::getline(std::cin, first_name);
	std::cout << "Last name :";
	std::getline(std::cin, last_name);
	std::cout << "Nickname :";
	std::getline(std::cin, nickname);
	std::cout << "Phone number :";
	std::getline(std::cin, phone_number);
	std::cout << "Darkest secret :";
	std::getline(std::cin, darkest_secret);
	contact = Contact(first_name, last_name,
				nickname, phone_number, darkest_secret);
	PhoneBook::addContact(contact);
}
std::string PhoneBook::cutContact(std::string str)
{
	if (str.length() >= 10)
	{
		str = str.substr(0, 9);
		str += ".";
	}
	return (str);
}

void PhoneBook::searchContact()
{
	int	index;
	int	data_count;
	std::string	first_name;
	std::string last_name;
	std::string nickname;

	index = 0;
	data_count = (this->contact_index < 8) ? this->contact_index : 7;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for (index = 0; index < data_count; index++)
	{
		first_name = contacts[index].getFirstName();
		last_name = contacts[index].getLastName();
		nickname = contacts[index].getNickName();
		std::cout << "|";
		std::cout << std::setw(10) << index + 1 << "|";
		std::cout << std::setw(10) << cutContact(first_name) << "|";
		std::cout << std::setw(10) << cutContact(last_name) << "|";
		std::cout << std::setw(10) << cutContact(nickname) << "|" << std::endl << std::endl;
	}
	std::cout << "Enter the index : ";
	std::cin >> index;
	if (this->contact_index == 0)
		std::cout << "Phonebook is empty" << std::endl;
	else if (index < data_count)
	{
		std::cout << "First name : " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last name : " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname : " << contacts[index].getNickName() << std::endl;
		std::cout << "Phone number : " << contacts[index].getPhoneNumber()<< std::endl;
		std::cout << "Darkest secret : " << contacts[index].getDarkestSecret()<< std::endl;
	}
}

PhoneBook::~PhoneBook()
{	
}