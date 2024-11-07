/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Addcontact_utils.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:06:55 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 12:50:23 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

void	ask_user_input(std::string &param)
{
	std::cout << "Enter the " << param << std::endl;
	std::getline(std::cin, param);
	if (param.empty())
		std::cout << "\033[31m"
					<< "Empty Input"
					<< "\033[0m" << std::endl;
}