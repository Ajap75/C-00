/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastruc <anastruc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:01:33 by anastruc          #+#    #+#             */
/*   Updated: 2025/01/06 16:37:29 by anastruc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "ctime"
#include "sstream"
#include "iostream"
#include "iomanip"
//Definition des variables statiques declarees dans le .hpp de la classe.
//Ces statiques sont propres a la classe elle meme et non aux instances. Chaque instance partagera ces meme valeurs.
//Lors de la definition dans le .cpp, on n'utilise pas static, le compilateur sait deja que ces definitions font references
// aux variables declare dans la class elle meme comme static. Si on rajoute static ici,
// le senms sera static pour "file_scop" ce qui change la potee de la variable et la
// rendra accessible uniquement dans ce fichier .cpp,

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << " accounts:"
	<< Account::getNbAccounts()
	<< ";total:"
	<< Account::getTotalAmount()
	<<";deposits:"
	<< Account::getNbDeposits()
	<< ";withdrawals:"
	<< Account::getNbWithdrawals()
	<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_amount += deposit;
	_totalNbDeposits += _nbDeposits;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << this->_amount 
	<< ";p_amount:"
	<< this->_amount - deposit 
	<< ";deposit:"
	<< deposit 
	<<":amount:"
	<< this-> _amount
	<<":nb_deposits:"
	<< this->_nbDeposits
	<< std::endl;
}
int		Account::checkAmount( void ) const
{
	return(Account::_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_amount
		<< ";p_amount:"
		<< this->_amount 
		<< ";withdrawal:";

	if (Account::checkAmount() >= withdrawal)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout
		<< withdrawal 
		<<":amount:"
		<< this-> _amount 
		<<":nb_withdrawals:"
		<< this->_nbWithdrawals;
	}
	else
	{
		std::cout
		<<"refused";
	}
	std::cout
	<< std::endl;
	return (false);
}

	void	Account::displayStatus( void ) const
{
		Account::_displayTimestamp();
		std::cout
		<< " index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";deposits:"
		<< this->_nbDeposits
		<<";withdrawals:"
		<< this->_nbWithdrawals
		<< std::endl;
}

//Toutes les fonctions membres doivent etre definies en dehors de la declaration de la classe et egalement en dehors des constructor
// et des destructor.

void	Account::_displayTimestamp(void)
{
	std::time_t now;
	std::tm *ltm;
	// obtenir l'heure actuelle
	now = std::time(0);
	//concertir l'heure en temps local
	ltm = std::localtime(&now);
	std::ostringstream oss;

	oss << "[" << (1900 + ltm->tm_year);
	oss << std::setw(2) << std::setfill('0') << (1 + ltm->tm_mon);
	oss << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_";
	oss << std::setw(2) << std::setfill('0') << ltm->tm_hour;
	oss << std::setw(2) << std::setfill('0') << ltm->tm_min;
	oss << std::setw(2) << std::setfill('0') << ltm->tm_sec;
	oss << "]";

	std::cout << oss.str();
}



//Definition des Constructor && destructor de l'instance (pas besoin de type de retour)
	Account::Account( int initial_deposit )
	{
		// Mise a jour des variables  static de la classe a chaque nouvelle instance
		_nbAccounts += 1;
		_totalAmount += initial_deposit;


		//Definitions des variables de la classe uniaue pour chaque instance en opposition aux statics communes
		// a chaque instance
		_accountIndex = _nbAccounts - 1;
		_amount = initial_deposit;
		_nbDeposits = 0;
		_nbWithdrawals = 0;

		//Message de creation d'instance
		_displayTimestamp();
		std::cout
		<< " index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";created"
		<< std::endl;
	}

	Account::~Account( void )
	{
		//Message de destruction d'instance
		_displayTimestamp();
		std::cout
		<< " index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";closed"
		<< std::endl;
	}






