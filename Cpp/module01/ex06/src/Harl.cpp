/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:56:15 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/02 13:36:05 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(void)
{
    return;
}

Harl::~Harl(void)
{
    return;
}

void    Harl::complain(std::string level) const
{
    int i = 0;
    
    void (Harl::*funct_arr[4])(void) const = 
    {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    std::string input[4] = {"debug", "info", "warning", "error"};
    
    for (; i < 4; i++)
    {
        if (level == input[i])
            break;
    }
    switch (i)
    {
        case (0):
            (this->*funct_arr[0])();
        case (1):
            (this->*funct_arr[1])();
        case (2):
            (this->*funct_arr[2])();
        case (3):
            (this->*funct_arr[3])();
            break;
        default:
            std::cout<<RED<<"The argument \""<<level<<"\""<<" is not a valid argument"<<std::endl;
            break;
    }
}

void Harl::_debug(void) const
{
    std::cout<<"THIS IS A DEBUG MESSAGE!"<<std::endl;
    return;
}

void Harl::_info(void) const
{
    std::cout<<"THIS IS AN INFO MESSAGE!"<<std::endl;
    return;
}

void Harl::_warning(void) const
{
    std::cout<<"THIS IS A WARNING MESSAGE!"<<std::endl;
    return;
}

void Harl::_error(void) const
{
    std::cout<<"THIS IS AN ERROR MESSAGE!"<<std::endl;
    return;
}
