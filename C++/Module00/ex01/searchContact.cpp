/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:03:45 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 11:27:39 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		is_valid_num(std::string str)
{
	int i = 0;

	while (str[i])
	{
		if (std::isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	prompt_one(PhonebookClass phonebook)
{
	std::string input = "";
	
	while (1)
	{
		std::cout<<YELLOW<<"Please choose an index to search for, or press"<<RED<<" BACK "<<YELLOW<<"to go back to menu:"<<std::endl;
		std::cout<<RESET;
		std::getline(std::cin, input);
		if (input == "BACK")
			break;
		else if (input== "")
			continue;
		else if (!is_valid_num(input))
		{
			std::cout<<RED<<"INDEX SHOULD BE A NUMBER"<<std::endl;
		}
		else
		{
			if (std::stoi(input) < 0 || std::stoi(input) > 7)
				std::cout<<RED<<"INDEX IS OUT OF RANGE, CHOOSE AN INDEX BETWEEN 0 and 7"<<std::endl;
			else if (phonebook.getContact(std::stoi(input)).getFirstName() == "")
				std::cout<<RED<<"THIS INDEX IS AN EMPTY FIELD, CHOOSE ANOTHER ONE"<<std::endl;
			else
			{
				display_user(phonebook, std::stoi(input));
				break;
			}
		}
	}
}
