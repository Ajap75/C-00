/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:05:57 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 17:39:30 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>
#include <sstream>

#include "../headers/utils.hpp"
#include "../headers/Contact.hpp"

void	ask_user_input(std::string &param, std::string str)
{
	while (1)
	{
	std::cout << MAGENTA <<  "Enter the " << str << RESET << std::endl;
	std::getline(std::cin, param);
	if (param.empty())
		std::cout << "\033[31m"
					<< "Empty Input, try again"
					<< "\033[0m" << std::endl;
	else
		return ;
	}
}

int stringtoint(const std::string& str)
{
	std::istringstream instance(str);
	int number;
	number = 0;
	instance >> number;
	if (instance.fail())
		std::cout << "\033[31m" << "Incorrect Index" << "\033[0m" << std::endl;
	return (number);

}

std::string truncate(std::string text)
{
	if (text.size() > 10)
		return (text.substr(0, 9) + ".");
	else
		return (text);
}

bool	isNumber(std::string search_index)
{
	unsigned long	i;

	i = 0;
	while (i < search_index.size() - 1)
	{
		if (!std::isdigit(search_index[i]))
			return (0);
	}
	return (1);
}
void	print_contact(Contact &new_contact)
{
	int	index;

	std::string first_name;
	std::string last_name;
	std::string nick_name;
	index = new_contact.get_index();
	first_name = new_contact.get_firstname();
	last_name = new_contact.get_last_name();
	nick_name = new_contact.get_nick_name();
	std::cout << BLUE << std::setw(10) << std::right << index << RESET << "|";
	std::cout << BLUE << std::setw(10) << std::right << truncate(first_name) << RESET << "|";
	std::cout << BLUE << std::setw(10) << std::right << truncate(last_name) << RESET << "|";
	std::cout << BLUE << std::setw(10) << std::right << truncate(nick_name) << RESET << std::endl;
	return ;
}

void	print_contact_info(int nbrcontacts, Contact *contacts, int search_index)
{
	int	i;

	i = 0;
	while (i < nbrcontacts)
	{
		if (contacts[i].get_index() == search_index)
		{
			std::cout << contacts[i].get_index() << std::endl;
			std::cout << contacts[i].get_firstname() << std::endl;
			std::cout << contacts[i].get_last_name() << std::endl;
			std::cout << contacts[i].get_nick_name() << std::endl;
			std::cout << contacts[i].get_darkest_secret() << std::endl;
			std::cout << contacts[i].get_number() << std::endl;
		}
		i++;
	}
}

void	print_header()
{
	std::cout << YELLOW << std::setw(10) << std::right << "Index" << RESET << "|" ;
	std::cout << YELLOW << std::setw(10) << std::right << "Fst Name" << RESET <<  "|";
	std::cout << YELLOW << std::setw(10) << std::right << "Lst Name" << RESET << "|";
	std::cout << YELLOW << std::setw(10) << std::right << "Nick Name" << RESET << std::endl;
}
void	print_phonebook(int nbrcontacts, Contact *contacts)
{
	int	i;

	if (contacts == NULL || nbrcontacts <= 0)
	{
		std::cout << "\033[31m" << "Your PhoneBook is empty" << "\033[0m" << std::endl;
		return ;
	}
	i = 0;
	print_header();
	while (i < nbrcontacts)
	{
		print_contact(contacts[i]);
		i++;
	}
	return ;
}
