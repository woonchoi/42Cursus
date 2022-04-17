/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:13:45 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/28 17:17:15 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class Phonebook {

private:
	Contact	contacts[8];
	int		contact_index;

public:
	Phonebook();
	void	add_contact(Contact contact);
	void	search_contact(int index);
};

#endif