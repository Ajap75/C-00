/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:24:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/05 17:54:04 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"
#include <string>
#include <cctype>
#include <iostream>

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

class PhoneBook
{
	private :
		Contact contacts[8];
		int	nbrcontacts;
		int index;

	public :

	PhoneBook ()  : nbrcontacts (0) {}

	void addcontact()
	{
		Contact new_contact ;
		int	contact_number;
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string darkest_secret;

		std::cout << "Enter the first_name" << std::endl;
		std::cin >> first_name;
		new_contact.set_firstname(first_name);

		std::cout << "Enter the last_name" << std::endl;
		std::cin >> last_name;
		new_contact.set_lastname(last_name);

		std::cout << "Enter the nick_name" << std::endl;
		std::cin >> nick_name;
		new_contact.set_nickname(nick_name);

		std::cout << "Enter the number" << std::endl;
		std::cin >> contact_number;
		new_contact.set_phonenumber(contact_number);


		std::cout << "Enter the darket_secret" << std::endl;
		std::cin >> darkest_secret;
		new_contact.set_darkestsecret(darkest_secret);

		if (nbrcontacts < 8)
			nbrcontacts += 1;

		index = nbrcontacts % 8;

		std::cout << "Contact succefully added" << std::endl;
		std::cout << "You have " << std::endl;


		// Enable the circularity. When nbrcontacts reaches 8,
		//  the index go back to 0, doing so we erase the oldest contact
	}

};

#endif


// Preciser le numero du contact ajouter. Trouver les codes couleurs de cout
