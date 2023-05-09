/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:09:10 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/28 15:39:31 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include <iostream>
#include <iomanip>

int main ()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout<<"\n---------------"<<std::endl;
    std::cout<<std::setw(40)<<std::left<<"Memodry Adress of the string variable: "<<&brain<<std::endl;
    std::cout<<std::setw(40)<<std::left<<"Memodry Adress held by stringPTR: "<<stringPTR<<std::endl;
    std::cout<<std::setw(40)<<std::left<<"Memodry Adress held by stringREF: "<<&stringREF<<std::endl;
    std::cout<<"---------------"<<std::endl;
    std::cout<<std::setw(40)<<std::left<<"Value of the string variable: "<<brain<<std::endl;
    std::cout<<std::setw(40)<<std::left<<"Value pointed to by stringPTR: "<<*stringPTR<<std::endl;
    std::cout<<std::setw(40)<<std::left<<"Value pointed to by stringREF: "<<stringREF<<std::endl;
    std::cout<<"---------------\n"<<std::endl;

    return (0);
}
