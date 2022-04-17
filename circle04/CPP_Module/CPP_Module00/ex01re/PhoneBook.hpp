/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:22:26 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/06 14:55:25 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	
	private:
		Contact 	contacts[8];
		int			contact_index;
		void		addContact(Contact contact);
		
	public:
		PhoneBook();
		void		inputContact();
		void		searchContact();
		std::string	cutContact(std::string str);
		~PhoneBook();
};

#endif