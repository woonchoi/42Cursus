/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:22:26 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/18 12:46:58 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	
	private:
		Contact 	contacts[8];
		int			contact_index;
		void		AddContact(Contact contact);
		
	public:
		PhoneBook();
		void		InputContact();
		void		SearchContact();
		std::string	CutContact(std::string str);
		~PhoneBook();
};

#endif