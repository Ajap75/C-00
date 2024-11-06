/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:24:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/06 17:12:09 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"
#include <string>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <cstdlib>

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP



void	print_contact_info(int nbrcontacts, Contact *contacts, int search_index)
{
	int i;
	i = 0;
	printf("Nbr contact = %d\n", nbrcontacts);
	if (search_index < 0 || search_index > (nbrcontacts - 1))
	{
		std::cout << "Incorrect Index" << std::endl;
	}
	while (i < nbrcontacts -1)
	{
		if(contacts[i].get_index() == search_index)
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
std::string	truncate(std::string text)
{
	if (text.size() > 10)
		return (text.substr(0, 9) + ".");
	else
		return (text);
}
void	print_contact(Contact &new_contact)
{
	int index;
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
	int i ;
	if (contacts == nullptr || nbrcontacts <= 0)
	{
		std::cout << "No contact." << std::endl;
		return;
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
	private :
		Contact contacts[8];
		int	nbrcontacts;
		int	index ;


	public :

	PhoneBook ()  : nbrcontacts (0), index(0){}

	void addcontact()
	{
		Contact new_contact ;
		std::string	contact_number;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string darkest_secret;

		if (nbrcontacts < 8)
		{
			nbrcontacts += 1;
		}
		index = index % 8;
		printf("INDEX =%d\n", index);
		printf("NBR CONTACT = %d\n", nbrcontacts);
		new_contact.set_index(index);

		std::cout << "Enter the first_name" << std::endl;
		std::getline(std::cin , first_name);
		if (first_name.empty())
			std::cout << "\033[31m" <<"Empty Input" << "\033[0m" << std::endl;
		printf("JE PASS LAfirst_name = %s\n", first_name.c_str());
		new_contact.set_firstname(first_name.c_str());

		std::cout << "Enter the last_name" << std::endl;
		std::getline(std::cin , last_name);
		if (last_name.empty())
			std::cout << "\033[31m" <<"Empty Input" << "\033[0m" << std::endl;
		new_contact.set_lastname(last_name);

		std::cout << "Enter the nick_name" << std::endl;
		std::getline(std::cin ,nick_name);
		if (nick_name.empty())
			std::cout << "\033[31m" <<"Empty Input" << "\033[0m" << std::endl;
		new_contact.set_nickname(nick_name);

		std::cout << "Enter the number" << std::endl;
		std::getline(std::cin, contact_number);
		if (contact_number.empty())
			std::cout << "\033[31m" <<"Empty Input" << "\033[0m" << std::endl;
		new_contact.set_phonenumber(contact_number);


		std::cout << "Enter the darket_secret" << std::endl;
		std::getline(std::cin , darkest_secret);
		if (darkest_secret.empty())
			std::cout << "\033[31m" <<"Empty Input" << "\033[0m" << std::endl;
		new_contact.set_darkestsecret(darkest_secret);


			// Enable the circularity. When nbrcontacts reaches 8,
			//  the index go back to 0, doing so we erase the oldest contact

		std::cout << "\033[32m" << "Contact succefully added" << std::endl << "You have " << nbrcontacts << " contacts registered"<< "\033[0m" << std::endl;
		printf("FIRST NAME = %s\n", first_name.c_str());

		contacts[index] = new_contact;
		index++;
	}

	void search ()
	{
		std::string search_index;

		print_phonebook(nbrcontacts, contacts);

		while(1)
		{
			std::getline(std::cin, search_index);
		if (!search_index.empty())
		{
			print_contact_info(nbrcontacts, contacts, stoi(search_index));
			return ;
		}
		}
	}

};


#endif