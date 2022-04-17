/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:13:20 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/05 14:48:59 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook()
{
	
}

void	Phonebook::add_contact(Contact contact)
{
	this->contacts[this->contact_index % 8] = contact;
	this->contact_index++;
}

void	Phonebook::search_contact(int index)
{
	this->contacts[index].
}
