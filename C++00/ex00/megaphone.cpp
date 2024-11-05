/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:19:51 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/05 12:08:32 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

class Megaphone
{
  public:
	std::string empty_string;

	Megaphone()
	{
		empty_string = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}

	std::string ToUpper(const std::string &input)
	{
		std::size_t i;
		std::string result;

		i = 0;
		result = input;

		while (i < result.size())
		{
			result[i] = std::toupper((unsigned char)result[i]);
			i++;
		}
		return (result);
	}
};



int	main(int argc, char **argv)
{
	std::string input;
	int i;
	Megaphone megaphone;

	i = 1;
	if (argc >= 2 && argv[i])
	{
		while (i < argc)
		{
			std::cout << megaphone.ToUpper(argv[i]);
			i++;
		}
	}
	if (argc < 2)
		std::cout << megaphone.empty_string << std::endl;
}