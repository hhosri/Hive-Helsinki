/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:56:15 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/02 13:15:17 by hel-hosr         ###   ########.fr       */
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
    void (Harl::*funct_arr[4])(void) const = 
    {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    std::string input[4] = {"debug", "info", "warning", "error"};
    if (level[0] == '\0')
    {
        std::cout<<RED<<"Argument is empty"<<std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (level == input[i])
        {
            (this->*funct_arr[i])();
            return;
        }
    }
    std::cout<<RED<<"The argument \""<<level<<"\""<<" is not a valid argument"<<std::endl;
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
