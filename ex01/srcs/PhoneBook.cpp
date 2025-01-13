/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:45 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/13 11:07:31 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PhoneBook.hpp"
#include "../headers/utils.hpp"
#include "stdio.h"


/********* Constructors/Destructors def : *********/

PhoneBook::PhoneBook() : nbrcontacts(0), index(0) {}
PhoneBook::~PhoneBook() {}




/********* Public members functions def : *********/

void PhoneBook::addcontact()
{
	Contact	new_contact;

	std::string contact_number;
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string darkest_secret;
	if (nbrcontacts < 8)
		nbrcontacts += 1;
	index = index % 8;
	// Enable the circularity. When nbrcontacts reaches 8,
	//  the index go back to 0, doing so we erase the oldest contact
	new_contact.set_index(index);
	ask_user_input(first_name, "first name");
	new_contact.set_firstname(first_name.c_str());
	ask_user_input(last_name, "last name");
	new_contact.set_lastname(last_name);
	ask_user_input(nick_name, "nick name");
	new_contact.set_nickname(nick_name);
	ask_user_input(contact_number, "contact number");
	new_contact.set_phonenumber(contact_number);
	ask_user_input(darkest_secret, "darkest secret");
	new_contact.set_darkestsecret(darkest_secret);
	std::cout << "\033[32m"
				<< "Contact succefully added" << std::endl
				<< "You have " << nbrcontacts << " contacts registered"
				<< "\033[0m" << std::endl;
	contacts[index] = new_contact;
	index++;
}

void PhoneBook::search()
{
	int	search_index_int;

	std::string search_index;
	if (print_phonebook(nbrcontacts, contacts))
		return ;
	std::cout << MAGENTA << "Enter the index of the desired contact" << RESET << std::endl;
	while (1)
	{
		std::getline(std::cin, search_index);
		search_index_int = stringtoint(search_index);
		if (search_index.empty() || !isNumber(search_index))
		{
			std::cout << "\033[31m" << "Incorrect Index : Empty or note a valid number" << "\033[0m" << std::endl;
			return ;
		}
		else if (search_index_int < 0 || search_index_int > (nbrcontacts - 1) || search_index_int > 7)
		{
			std::cout << "\033[31m" << "Incorrect Index : No contact matches" << "\033[0m" << std::endl;
			return ;
		}
		else
			print_contact_info(nbrcontacts, contacts, search_index_int);
		return ;
	}
}




/********* Private members functions def : *********/


void	PhoneBook::ask_user_input(std::string &param, std::string str)
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

int PhoneBook::stringtoint(const std::string& str)
{
	std::istringstream instance(str);
	int number;
	number = 0;
	instance >> number;
	if (instance.fail())
		return (-1);
	return (number);
}

std::string PhoneBook::truncate(std::string text)
{
	if (text.size() > 10)
		return (text.substr(0, 9) + ".");
	else
		return (text);
}

bool	PhoneBook::isNumber(std::string search_index)
{
	unsigned long	i;

	i = 0;
	while (i < search_index.size())
	{
		if (!std::isdigit(search_index[i]))
			return (0);
		i++;
	}
	return (1);
}

void	PhoneBook::print_contact(Contact &new_contact)
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

void	PhoneBook::print_contact_info(int nbrcontacts, Contact *contacts, int search_index)
{
	int	i;

	i = 0;
	while (i < nbrcontacts)
	{
		if (contacts[i].get_index() == search_index)
		{
			std::cout << GREEN << "INDEX = " << contacts[i].get_index() << std::endl;
			std::cout << "First Name = " << contacts[i].get_firstname() << std::endl;
			std::cout << "Last Name = " << contacts[i].get_last_name() << std::endl;
			std::cout << "Nick Name = " << contacts[i].get_nick_name() << std::endl;
			std::cout << "Darkest Secret = " << contacts[i].get_darkest_secret() << std::endl;
			std::cout << "Number = " << contacts[i].get_number() << RESET << std::endl;
			return ;
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

int	PhoneBook::print_phonebook(int nbrcontacts, Contact *contacts)
{
	int	i;

	if (contacts == NULL || nbrcontacts <= 0)
	{
		std::cout << "\033[31m" << "Your PhoneBook is empty" << "\033[0m" << std::endl;
		return 1;
	}
	i = 0;
	print_header();
	while (i < nbrcontacts)
	{
		print_contact(contacts[i]);
		i++;
	}
	return 0;
}




