/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:24:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 11:05:56 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

void	ask_user_input(std::string& param)
{
		std::cout << "Enter the " << param << std::endl;
		std::getline(std::cin, param);
		if (param.empty())
			std::cout << "\033[31m"
						<< "Empty Input"
						<< "\033[0m" << std::endl;
}

bool	isNumber(std::string search_index)
{
	unsigned long i;
	i = 0;

	while (i < search_index.size() - 1)
	{
		if (!std::isdigit(search_index[i]))
			return (0);
	}
	return (1);
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
std::string truncate(std::string text)
{
	if (text.size() > 10)
		return (text.substr(0, 9) + ".");
	else
		return (text);
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
	// printf("FIRST NAME = %s\n", first_name.c_str());
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << truncate(first_name.c_str()) << "|";
	std::cout << std::setw(10) << std::right << truncate(last_name) << "|";
	std::cout << std::setw(10) << std::right << truncate(nick_name) << std::endl;
	return ;
}
void	print_phonebook(int nbrcontacts, Contact *contacts)
{
	int	i;

	if (contacts == nullptr || nbrcontacts <= 0)
	{
		std::cout << "No contact." << std::endl;
		return ;
	}
	i = 0;
	while (i < nbrcontacts)
	{
		print_contact(contacts[i]);
		i++;
	}
	return ;
}

class PhoneBook
{
  private:
	Contact contacts[8];
	int nbrcontacts;
	int index;

  public:
	PhoneBook() : nbrcontacts(0), index(0) {}
	~PhoneBook() {}

	void addcontact()
	{
		Contact new_contact;
		std::string contact_number;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string darkest_secret;

		if (nbrcontacts < 8)
		{
			nbrcontacts += 1;
		}
		index = index % 8;
		// Enable the circularity. When nbrcontacts reaches 8,
		//  the index go back to 0, doing so we erase the oldest contact
		new_contact.set_index(index);

		ask_user_input(first_name);
		new_contact.set_firstname(first_name.c_str());
		ask_user_input(last_name);
		new_contact.set_lastname(last_name);
		ask_user_input(nick_name);
		new_contact.set_nickname(nick_name);
		ask_user_input(contact_number);
		new_contact.set_phonenumber(contact_number);
		ask_user_input(darkest_secret);
		new_contact.set_darkestsecret(darkest_secret);

		std::cout << "\033[32m"
					<< "Contact succefully added" << std::endl
					<< "You have " << nbrcontacts << " contacts registered"
					<< "\033[0m" << std::endl;
		printf("FIRST NAME = %s\n", first_name.c_str());

		contacts[index] = new_contact;
		index++;
	}



	void search()
	{
		std::string search_index;
		int search_index_int;

		print_phonebook(nbrcontacts, contacts);
		while (1)
		{
			std::getline(std::cin, search_index);
			if (search_index.empty() || !isNumber(search_index))
			{
				printf("TEST\n");
				std::cout << "Incorrect Index" << std::endl;
				return ;
			}
			search_index_int = stoi(search_index);
			if (search_index_int < 0 || search_index_int > (nbrcontacts - 1))
				std::cout << "Incorrect Index" << std::endl;
			else
				print_contact_info(nbrcontacts, contacts, stoi(search_index));
			return ;
		}
	}
};




#endif