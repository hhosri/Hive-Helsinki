/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:34 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 12:56:21 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhonebookClass.hpp"

PhonebookClass::PhonebookClass(void)
{
	this->current_idx = 0;
	this->entries = 0;
	return;
}

PhonebookClass::~PhonebookClass(void)
{
	return;
}

void PhonebookClass::addContact(ContactClass contact)
{
	if (this->current_idx > 7)
	{
		this->current_idx = this->current_idx % 8;
		// this->entries = 1;
	}
	this->_contacts[this->current_idx] = contact;
	this->current_idx++;
	this->entries++;
	return;
}

ContactClass PhonebookClass::getContact(int index) const
{
	return (this->_contacts[index]);
}

int PhonebookClass::getEntriesNum(void) const
{
	return (this->entries);
} 