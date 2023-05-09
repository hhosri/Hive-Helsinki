/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayContacts.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:35:35 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 11:24:13 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string truncator(std::string str)
{
	if(str.length() > 10)
	{
		str = str.substr(0,9);
		str += ".";
	}
	return (str);
}

static void	beautiful_stuff()
{
	std::cout <<BLUE;
	std::cout << "\t|----------|----------|----------|----------|"<< std::endl;
	std::cout << "\t|";
	std::cout <<std::setw(10)<<std::left<<"INDEX";
	std::cout << "|";
	std::cout <<std::setw(10)<<std::left<<"FIRST NAME";
	std::cout << "|";
	std::cout <<std::setw(10)<<std::left<<"LAST NAME";
	std::cout << "|";
	std::cout <<std::setw(10)<<std::left<<"NICKNAME";
	std::cout << "|"<<std::endl;
	std::cout << "\t|----------|----------|----------|----------|"<< std::endl;
	std::cout << RESET;
}

void	display_empty(void)
{
	std::cout<<BLUE<<"\t|"<<RED<<std::setw(43)<<"            *PHONEBOOK IS EMPTY*"<<BLUE<<"|"<<std::endl;
	std::cout <<BLUE<< "\t|-------------------------------------------|"<< std::endl;
	return;
}

void	display_user(PhonebookClass phonebook, int index)
{
	std::cout<<std::endl;
	std::cout<<std::left;
	std::cout<<BLUE<< "-------------------------------------------"<< std::endl;
	std::cout<<BLUE<<"INFO FOR: "<<RED<<phonebook.getContact(index).getFirstName()<<" "<<phonebook.getContact(index).getLastName()<<BLUE<<std::endl;
	std::cout<<BLUE<< "-------------------------------------------"<< std::endl;
	std::cout<<BLUE<<std::setw(20)<<"First Name:"<<RESET<<phonebook.getContact(index).getFirstName()<<std::endl;
	std::cout<<BLUE<<std::setw(20)<<"Last Name:"<<RESET<<phonebook.getContact(index).getLastName()<<std::endl;
	std::cout<<BLUE<<std::setw(20)<<"Nickname:"<<RESET<<phonebook.getContact(index).getNickname()<<std::endl;
	std::cout<<BLUE<<std::setw(20)<<"Phone number:"<<RESET<<phonebook.getContact(index).getNumber()<<std::endl;
	std::cout<<BLUE<<std::setw(20)<<"Darkest Secrets:"<<RESET<<phonebook.getContact(index).getDarkestSecret()<<std::endl;
	std::cout<<BLUE<< "-------------------------------------------"<< std::endl;
	std::cout<<std::endl;
}

void	display_all(PhonebookClass phonebook)
{
	int i = 0;

	beautiful_stuff();

	while(i <= 7)
	{
		if (phonebook.getContact(i).getFirstName()[0] == '\0')
			break;
		std::string name = truncator(phonebook.getContact(i).getFirstName());
		std::string lastName = truncator(phonebook.getContact(i).getLastName());
		std::string nickname = truncator(phonebook.getContact(i).getNickname());
		
		std::cout<<BLUE<<"\t|"<<YELLOW<<std::setw(10)<<std::right<<i;
		std::cout<<BLUE<<"|"<<GREEN<<std::setw(10)<<std::right<<name;
		std::cout<<BLUE<<"|"<<GREEN<<std::setw(10)<<std::right<<lastName;
		std::cout<<BLUE<<"|"<<GREEN<<std::setw(10)<<std::right<<nickname<<BLUE<<"|"<<std::endl;
		std::cout <<BLUE<< "\t|-------------------------------------------|"<< std::endl;
		i++;
	}
}