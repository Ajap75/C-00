/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:45 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/06 15:26:01 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PhoneBook.hpp"
#include "../headers/utils.hpp"

PhoneBook::PhoneBook() : nbrcontacts(0), index(0) {}
PhoneBook::~PhoneBook() {}


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
	print_phonebook(nbrcontacts, contacts);
	while (1)
	{
		std::getline(std::cin, search_index);
		if (search_index.empty() || !isNumber(search_index))
		{
			std::cout << "\033[31m" << "Incorrect Index" << "\033[0m" << std::endl;
			return ;
		}
		search_index_int = stringtoint(search_index);
		if (search_index_int < 0 || search_index_int > (nbrcontacts - 1))
		{
			std::cout << "\033[31m" << "Incorrect Index" << "\033[0m" << std::endl;
			return ;
		}
		else
			print_contact_info(nbrcontacts, contacts, search_index_int);
		return ;
	}
}



