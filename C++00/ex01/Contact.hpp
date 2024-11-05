/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:27:35 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/05 16:20:27 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <cctype>

class Contact
{
	public:
		Contact() : m_phone_number(0) {}

	void set_phonenumber(const int phone_number)
	{
		Contact::m_phone_number = phone_number;
	}
	void set_firstname(const std::string& first_name)
	{
		Contact::m_first_name = first_name;
	}
	void set_lastname(const std::string& last_name)
	{
		Contact::m_last_name = last_name;
	}
	void set_nickname(const std::string& nick_name)
	{
		Contact::m_nick_name = nick_name;
	}
	void set_darkestsecret(const std::string& darkest_secret)
	{
		Contact::m_darkest_secret = darkest_secret;
	}

	private:

	int	index ;
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nick_name;
	int m_phone_number;
	std::string m_darkest_secret;

} ;

#endif