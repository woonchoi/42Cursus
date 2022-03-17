/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:57:37 by woonchoi          #+#    #+#             */
/*   Updated: 2022/03/14 16:00:49 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>
#include <string>

int	main(int argc, char **argv)
{
	std::locale loc;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for(int j = 0; j < str.length(); j++)
			{
				char &ch = str[j];
				ch = std::toupper(ch, loc);
			}
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}
