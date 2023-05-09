/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:32:21 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 17:44:36 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = nullptr;
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    return;
}

void    HumanB::attack(void) const
{
    if (this->_weapon == nullptr)
        std::cout<<this->_name<<" doesn't have any weapon!"<<std::endl;
    else
        std::cout<<this->_name<<" attacks with their "<<(*_weapon).getType()<<std::endl;
    return;
}