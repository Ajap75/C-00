/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:27:35 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 16:53:05 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
  private:
	int m_index;
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nick_name;
	std::string m_phone_number;
	std::string m_darkest_secret;

  public:
  //constructor
	Contact() {}
  //destructor
	~Contact() {}


	void set_index(const int index);
	void set_phonenumber(const std::string phone_number);
	void set_firstname(const std::string first_name);
	void set_lastname(const std::string last_name);
	void set_nickname(const std::string nick_name);
	void set_darkestsecret(const std::string darkest_secret);
	const std::string get_firstname();
	const std::string get_last_name();
	const std::string get_nick_name();
	const std::string get_darkest_secret();
	const std::string get_number();
	int get_index();
};

#endif