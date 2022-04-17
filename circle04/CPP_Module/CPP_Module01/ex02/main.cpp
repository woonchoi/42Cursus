/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:50:45 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/11 14:57:20 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string address : " << &str << std::endl;
	std::cout << "stringPTR value : " << stringPTR << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;
	
	std::cout << "print string : " << str << std::endl;
	std::cout << "print string with stringPTR : " << *stringPTR << std::endl;
	std::cout << "print string with stringREF : " << stringREF << std::endl;
	return (0);
}