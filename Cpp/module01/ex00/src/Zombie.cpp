/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:51:32 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 18:07:39 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    return;
}

Zombie::~Zombie(void)
{
    std::cout<<this->_name<<" IS DESTROYED"<<std::endl;
    return;
}

void Zombie::announce(void)
{
    std::cout<<this->_name<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
    return;
}