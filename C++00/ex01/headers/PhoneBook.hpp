/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:24:09 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 12:52:38 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

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