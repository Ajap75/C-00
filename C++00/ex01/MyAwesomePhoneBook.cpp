/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:35:45 by anastruc          #+#    #+#             */
/*   Updated: 2024/11/05 17:50:03 by anastruc         ###   ########.fr       */
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

	std::cout << "Welcome to your Phonebook" << std::endl;
	std::cout << "Choose a command = ADD, SEARCH or EXIT" << std::endl;
	while (1)
	{
		std::cin >> input;
		if (input.compare("ADD") == 0)
		{
			my_phonebook.addcontact();
			input.erase();
			//enregistrer un nouveau contact
			//Si l’utilisateur entre cette commande, le programme lui demande de remplir
			// une par une les informations du nouveau contact. Une fois tous les champs
			// complétés, le nouveau contact est ajouté au répertoir
			// Les champs d’un contact enregistré nE peuvent être vides.
		}
// 		else if (input.compare("SEARCH") == 0)
// 		{
// 			// Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
// 			//first name, last name et nickname.
// ◦ 			//Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
// 			//par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
// 			//de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
// 			//un point (’.’).
// 			//Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à af-
// 			//ficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
// 			//Sinon, affichez les informations du contact, une par ligne.
// 		}
// 		else if (input.compare("EXIT") == 0)
// 		{
// 			//DELET LES CONTACT ET EXIT
// 		}
	}
}


// Creer les deux Class, contact et phone booke en utilisant toutes les notions abordees par les videos et dans le sujet.
// Dans la Class PhoneBook, il va falloir creer des fonctions membres pour l'ajout d'un contact, la reearch.
// Dans le phonebook, il va falloir creer un attribut de type tableau de contact (tableau de class contact).
// Ce tableau se vera ajoute une instance de Class Contact a chaque appel de la fonction membre add. Une fois la huitieme instance cree, la premiere instance est remplace par la nouvelle.
// Pour chacun des attributs et des fonctions membres que je vais declarer, il faudra reflechir au besoin que la varaible soit public ou privee.
// Dans la meme veine, il faut que je "constante" au maximum mon code.