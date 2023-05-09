/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:10:25 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 11:51:26 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static std::string remove_white(std::string str)
{
	int i = 0;
	std::string new_str;

	while (str[i] == ' ' || str[i] == '\t')
	{
		i++;
	}
	new_str = str.substr(i);
	return(new_str);
}

ContactClass	create_contact()
{
	std::string input;
	ContactClass newContact;

	while (input == "")
	{
		std::cout<<BOLD<<BLUE<< "Enter your name:";
		std::cout<<REGULAR<<RESET;
		std::getline(std::cin, input);
		input = remove_white(input);
		if (input != "")
			newContact.setFirstName(input);
	}
	input = "";
	while (input == "")
	{
		std::cout<<BOLD<<BLUE<< "Enter your last name:";
		std::cout<<REGULAR<<RESET;
		std::getline(std::cin, input);
		input = remove_white(input);
		if (input != "")
			newContact.setLastName(input);
	}
	input = "";
	while (input == "")
	{
		std::cout<<BOLD<<BLUE<< "Enter your nickname:";
		std::cout<<REGULAR<<RESET;
		std::getline(std::cin, input);
		input = remove_white(input);
		if (input != "")
			newContact.setNickname(input);
	}
	input = "";
	while (input == "")
	{
		std::cout<<BOLD<<BLUE<< "Enter your darkest secrets:";
		std::cout<<REGULAR<<RESET;
		std::getline(std::cin, input);
		input = remove_white(input);
		if (input != "")
			newContact.setDarkestSecret(input);
	}
	input = "";
	while (input == "")
	{
		std::cout<<BOLD<<BLUE<< "Enter your phone number:";
		std::cout<<REGULAR<<RESET;
		std::getline(std::cin, input);
		input = remove_white(input);
		if (!is_valid_num(input))
		{
			input = "";
			std::cout<<RED<<"Please enter a valid number"<<std::endl;
		}
		else
		{
			if (input != "")
				newContact.setNumber(input);
		}
	}
	input = "";

	std::cout<<GREEN<<"CONTACT SUCCESFULLY ADDED!"<<std::endl;
	return (newContact);
}