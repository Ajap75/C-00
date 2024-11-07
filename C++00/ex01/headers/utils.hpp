/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:14:02 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 17:39:16 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

#define MAGENTA "\033[35m"
#define RED  "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN  "\033[32m"
#define FLASHING  "\033[5m"
#define BLUE "\033[34m"
#define RESET "\033[39m"

void	ask_user_input(std::string &param, std::string str);
int		stringtoint(const std::string &str);
std::string truncate(std::string text);
bool	isNumber(std::string search_index);
void	print_contact(Contact &new_contact);
void	print_contact_info(int nbrcontacts, Contact *contacts,
			int search_index);
void	print_phonebook(int nbrcontacts, Contact *contacts);

#endif