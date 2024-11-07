/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:27:35 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 10:52:22 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <cctype>

class Contact
{
	private:

	int	m_index ;
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nick_name;
	std::string m_phone_number;
	std::string m_darkest_secret;

	public:
		Contact() {}
		~Contact () {}

	void set_index(const int index)
	{
		Contact::m_index = index;
	}
	void set_phonenumber(const std::string phone_number)
	{
		Contact::m_phone_number = phone_number;
	}
	void set_firstname(const std::string first_name)
	{
		Contact::m_first_name = first_name;
		printf("SET FIRST NAME = %s\n", m_first_name.c_str());
	}
	void set_lastname(const std::string last_name)
	{
		Contact::m_last_name = last_name;
	}
	void set_nickname(const std::string nick_name)
	{
		Contact::m_nick_name = nick_name;
	}
	void set_darkestsecret(const std::string darkest_secret)
	{
		Contact::m_darkest_secret = darkest_secret;
	}
	const std::string get_firstname()
	{
		return(this->m_first_name);
	}
	const std::string get_last_name()
	{
		return (this->m_last_name);
	}
	const std::string get_nick_name()
	{
		return(this->m_nick_name);
	}

	const std::string get_darkest_secret()
	{
		return(this->m_darkest_secret);
	}

	const std::string get_number()
	{
		return (this->m_phone_number);
	}

	int get_index()
	{
		return (this->m_index);
	}


} ;

#endif