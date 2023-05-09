/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:32:21 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 17:44:25 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :_weapon(weapon)
{
    this->_name = name;
    return;
}

HumanA::~HumanA(void)
{
    return;
}

void    HumanA::attack(void) const
{
    std::cout<<this->_name<<" attacks with their "<<this->_weapon.getType()<<std::endl;
    return;
}