/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:24:09 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/08 18:54:07 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
  
	//Members attributs
	Contact contacts[8];
	int nbrcontacts;
	int index;
	
	//Member functions
	void	ask_user_input(std::string &param, std::string str);
	int		stringtoint(const std::string &str);
	std::string truncate(std::string text);
	bool	isNumber(std::string search_index);
	void	print_contact(Contact &new_contact);
	void	print_contact_info(int nbrcontacts, Contact *contacts,
			int search_index);
	int	print_phonebook(int nbrcontacts, Contact *contacts);

  public:
  
	//Constructor & destructor
	PhoneBook();
	~PhoneBook();
	
	//Member functions
	void addcontact();
	void search();
};

#endif