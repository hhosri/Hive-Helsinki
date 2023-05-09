/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:34:15 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/09 10:44:58 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

//default constructor
FragTrap::FragTrap(void)
{
    this->_name = "Anonymous";
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout<<YELLOW<<this->_name<<BLUE<<" is Born! as FRAG"<<RESET<<std::endl;
    return;
}

//string constructor
FragTrap::FragTrap(std::string name) :ClapTrap(name)
{
    this->_name = name;
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
     std::cout<<YELLOW<<this->_name<<BLUE<<" is Born as FRAG"<<RESET<<std::endl;
    return;
}
//copy constructor
FragTrap::FragTrap(const FragTrap &src)
{
    *this = src;
    return;
}

//assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &rh_src)
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
FragTrap::~FragTrap(void)
{
    std::cout<<YELLOW<<this->_name<<BLUE<<" is Destroyed, as FRAG"<<RESET<<std::endl;
    return;
}

//member functions
void    FragTrap::attack(const std::string &target)
{
    if (this->_energy_points == 0 || this->_hit_points == 0)
    {
        if (this->_hit_points == 0)
            std::cout<<RED<<"Cannot attack, "<<this->_name<<" is a useless potato now :( as FRAG"<<RESET<<std::endl;
        else
            std::cout<<RED<<"Cannot attack, "<<this->_name<<" has no more energy as FRAG"<<RESET<<std::endl;
    }
    else
    {
        std::cout<<MAGENTA<<this->_name<<" attacks "<<target<<" causing "<<this->_attack_damage<<" points of damage as FRAG"<<RESET<<std::endl;
        this->_energy_points--;
    }
}

void    FragTrap::highFivesGuys(void)
{
    std::cout<<RED<<"CAN I GET A HIVE FIVE ?!"<<std::endl;
}