/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:20:45 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 15:42:45 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Contact.hpp"
#include <iostream>

void Contact::set_index(const int index)
{
	m_index = index;
}
void Contact::set_phonenumber(const std::string phone_number)
{
	m_phone_number = phone_number;
}
void Contact::set_firstname(const std::string first_name)
{
	m_first_name = first_name;
}
void Contact::set_lastname(const std::string last_name)
{
	m_last_name = last_name;
}
void Contact::set_nickname(const std::string nick_name)
{
	Contact::m_nick_name = nick_name;
}
void Contact::set_darkestsecret(const std::string darkest_secret)
{
	Contact::m_darkest_secret = darkest_secret;
}
const std::string Contact::get_firstname()
{
	return (this->m_first_name);
}
const std::string Contact::get_last_name()
{
	return (this->m_last_name);
}
const std::string Contact::get_nick_name()
{
	return (this->m_nick_name);
}
const std::string Contact::get_darkest_secret()
{
	return (this->m_darkest_secret);
}
const std::string Contact::get_number()
{
	return (this->m_phone_number);
}
int Contact::get_index()
{
	return (this->m_index);
}