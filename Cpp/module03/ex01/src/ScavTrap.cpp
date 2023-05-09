/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:37:14 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/08 16:51:00 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

//default constructor
ScavTrap::ScavTrap(void)
{
    this->_name = "Anonymous";
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
    std::cout<<YELLOW<<this->_name<<BLUE<<" is Born! as SCAV"<<RESET<<std::endl;
    return;
}

//string constructor
ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
     std::cout<<YELLOW<<this->_name<<BLUE<<" is Born as SCAV"<<RESET<<std::endl;
    return;
}
//copy constructor
ScavTrap::ScavTrap(const ScavTrap &src)
{
    *this = src;
    return;
}

//assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &rh_src)
{
    if (this != &rh_src)
    {
        this->_name = rh_src.get_name();
        this->_hit_points = rh_src.get_hit_points();
        this->_energy_points = rh_src.get_energy_points();
        this->_attack_damage = rh_src.get_attack_damage();
    }
    return (*this);
}

//destructor
ScavTrap::~ScavTrap(void)
{
    std::cout<<YELLOW<<this->_name<<BLUE<<" is Destroyed, as SCAV"<<RESET<<std::endl;
    return;
}

//member functions
void    ScavTrap::attack(const std::string &target)
{
    if (this->_energy_points == 0 || this->_hit_points == 0)
    {
        if (this->_hit_points == 0)
            std::cout<<RED<<"Cannot attack, "<<this->_name<<" is a useless potato now :( as SCAV"<<RESET<<std::endl;
        else
            std::cout<<RED<<"Cannot attack, "<<this->_name<<" has no more energy as SCAV"<<RESET<<std::endl;
    }
    else
    {
        std::cout<<MAGENTA<<this->_name<<" attacks "<<target<<" causing "<<this->_attack_damage<<" points of damage as SCAV"<<RESET<<std::endl;
        this->_energy_points--;
    }
}

void   ScavTrap::guardGate()
{
    std::cout<<"ScavTrap "<<this->_name<<" is in gate keeper mode! "<<std::endl;
}