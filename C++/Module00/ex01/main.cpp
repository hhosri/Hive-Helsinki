/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:28 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 13:02:47 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main ()
{
	std::string	input;
	PhonebookClass phonebook;
	ContactClass newContact;

	std::cout<<MAGENTA<<"* Welcome to PHONEBOOK v1.0.0 *"<<std::endl;
	while (1)
	{
		std::cout<<YELLOW<<"Please choose an option:"<<BLUE<<"ADD | SEARCH | EXIT"<<std::endl;
		std::cout<<RESET;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			newContact = create_contact();
			if(phonebook.getEntriesNum() >= 8)
				std::cout<<RED<<"An entry has just been overwritten"<<RESET<<std::endl;
			phonebook.addContact(newContact);
		}
		else if (input == "SEARCH")
		{
			display_all(phonebook);
			if (phonebook.getEntriesNum() == 0)
				display_empty();
			else
				prompt_one(phonebook);
		}
		else if (input == "EXIT")
		{
			std::cout<<MAGENTA<<"* Thank you for using PHONEBOOK v.1.0.0 *"<<std::endl;
			break;
		}
		else if (input != "")
			std::cout<<RED<<"INVALID COMMAND: \""<<input<<"\""<<std::endl;
	}
	return (0);
}