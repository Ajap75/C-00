/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:46:05 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/06 15:13:10 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PhoneBook.hpp"
#include "../headers/utils.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook my_phonebook;

	std::string input;
	std::cout << YELLOW << "\n\n        WELCOME TO YOUR PHONEBOOK\n" << RESET << std::endl;
	std::cout << YELLOW << "Choose a command : \n\n\nADD \n\nSEARCH \n\nEXIT\n\n" << RESET << std::endl;
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


// Errors handled : 
// SEARCH in an EMPTY PHONE BOOKE
// Search with a wrong Index 
// Empty entry while adding a contact