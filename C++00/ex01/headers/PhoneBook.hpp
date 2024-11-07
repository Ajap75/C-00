/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:24:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 15:34:56 by anastruc         ###   ########.fr       */
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

  public:
	//Constructor & destructor
	PhoneBook() : nbrcontacts(0), index(0)
	{
	}
	~PhoneBook()
	{
	}
	//Member functions
	void addcontact();
	void search();
};

#endif