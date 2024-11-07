/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:05:57 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 12:52:52 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.hpp"

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
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << truncate(first_name.c_str()) << "|";
	std::cout << std::setw(10) << std::right << truncate(last_name) << "|";
	std::cout << std::setw(10) << std::right << truncate(nick_name) << std::endl;
	return ;
}