/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:42:33 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/08 14:28:48 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../headers/Account.hpp"

int main ()
{
	Account myaccount(1000);
	Account::displayAccountsInfos();
	return (0);
}