/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:46:05 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 12:49:38 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook my_phonebook;

	std::string input;
	std::cout << "\033[33m"
				<< "WELCOME TO YOUR PHONEBOOK"
				<< "\033[0m" << std::endl;
	std::cout << "Choose a command = ADD, SEARCH or EXIT" << std::endl;
	while (1)
	{
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			my_phonebook.addcontact();
		else if (input.compare("SEARCH") == 0)
			my_phonebook.search();
		else if (input.compare("EXIT") == 0)
			return (0);
	}
}