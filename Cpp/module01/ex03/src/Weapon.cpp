/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:13:57 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 17:45:02 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
    return;
}

Weapon::~Weapon(void)
{
    return;
}

const std::string &Weapon::getType(void) const
{
    return (this->_type);
}

void        Weapon::setType(std::string new_type)
{
    this->_type = new_type;
    return;
}