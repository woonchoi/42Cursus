/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:11:21 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/18 12:47:50 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	Contact("", "", "", "", "");
}

Contact::Contact(std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string Contact::GetFirstName()
{
	return (first_name);
}

std::string Contact::GetLastName()
{
	return (last_name);
}

std::string Contact::GetNickName()
{
	return (nickname);
}

std::string	Contact::GetPhoneNumber()
{
	return (phone_number);
}

std::string	Contact::GetDarkestSecret()
{
	return (darkest_secret);
}

Contact::~Contact()
{
}
