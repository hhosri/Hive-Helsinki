/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:14 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 11:22:08 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ContactClass.hpp"

/*-----------CONST/DEST---------------------------*/
ContactClass::ContactClass(void)
{
	return;
}

ContactClass::~ContactClass(void)
{
	return;
}

/*----------------GET----------------------------*/
std::string ContactClass::getFirstName (void) const
{
	return (this->_firstName );
}

std::string ContactClass::getLastName (void) const
{
	return (this->_lastName);
}

std::string ContactClass::getNickname (void) const
{
	return (this->_nickname);
}

std::string ContactClass::getDarkestSecret (void) const
{
	return (this->_darkestSecret);
}

std::string	ContactClass::getNumber (void) const
{
	return (this->_number);
}

/*----------------SET----------------------------*/

void	ContactClass::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
	return;
}

void	ContactClass::setLastName(std::string lastName)
{
	this->_lastName = lastName;
	return;
}

void 	ContactClass::setNickname(std::string nickname)
{
	this->_nickname = nickname;
	return;
}

void	ContactClass::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
	return;
}

void	ContactClass::setNumber(std::string number)
{
	this->_number = number;
	return;
}