/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:45 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/07 10:45:48 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <cctype>
#include <iostream>

int	main ()
{
	std::string input;
	PhoneBook my_phonebook;

	std::cout << "\033[33m" << "WELCOME TO YOUR PHONEBOOK" << "\033[0m" << std::endl;
	std::cout << "Choose a command = ADD, SEARCH or EXIT" << std::endl;
	while (1)
	{
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0)
			my_phonebook.addcontact();
		else if (input.compare("SEARCH") == 0)
			my_phonebook.search();
		else if (input.compare("EXIT") == 0)
			return (0);
	}
}


// Creer les deux Class, contact et phone booke en utilisant toutes les notions abordees par les videos et dans le sujet.
// Dans la Class PhoneBook, il va falloir creer des fonctions membres pour l'ajout d'un contact, la reearch.
// Dans le phonebook, il va falloir creer un attribut de type tableau de contact (tableau de class contact).
// Ce tableau se vera ajoute une instance de Class Contact a chaque appel de la fonction membre add. Une fois la huitieme instance cree, la premiere instance est remplace par la nouvelle.
// Pour chacun des attributs et des fonctions membres que je vais declarer, il faudra reflechir au besoin que la varaible soit public ou privee.
// Dans la meme veine, il faut que je "constante" au maximum mon code.