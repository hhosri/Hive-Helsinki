/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:48:52 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/08 15:31:44 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

//default constructor
ClapTrap::ClapTrap(void): _hit_points(10), _energy_points(10), _attack_damage(0)
{
    this->_name = "Anonymous";
    std::cout<<YELLOW<<this->_name<<BLUE<<" is Born!"<<RESET<<std::endl;
    return;
}

//string constructor
ClapTrap::ClapTrap(std::string name): _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout<<YELLOW<<name<<BLUE<<" is Born!"<<RESET<<std::endl;
    this->_name = name;
    return;
}
//copy constructor
ClapTrap::ClapTrap(const ClapTrap &src)
{
    *this = src;
    return;
}

//assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &rh_src)
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
ClapTrap::~ClapTrap(void)
{
    std::cout<<YELLOW<<this->_name<<BLUE<<" is Destroyed!"<<RESET<<std::endl;
    return;
}


//---------------------get-set
//SET
void    ClapTrap::set_hit_points(int value)
{
    this->_hit_points = value;
    return;
}

void    ClapTrap::set_energy_points(int value)
{
    this->_energy_points = value;
    return;
}

void    ClapTrap::set_attack_damage(int value)
{
    this->_attack_damage = value;
    return;
}

//GET
int   ClapTrap::get_hit_points(void) const
{
    return(this->_hit_points);
}

int   ClapTrap::get_energy_points(void) const
{
    return(this->_energy_points);
}

int   ClapTrap::get_attack_damage(void) const
{
    return(this->_attack_damage);
}

std::string ClapTrap::get_name(void) const
{
    return(this->_name);
}

//member functions
void    ClapTrap::attack(const std::string &target)
{
    if (this->_energy_points == 0 || this->_hit_points == 0)
    {
        if (this->_hit_points == 0)
            std::cout<<RED<<"Cannot attack, "<<this->_name<<" is a useless potato now :("<<RESET<<std::endl;
        else
            std::cout<<RED<<"Cannot attack, "<<this->_name<<" has no more energy"<<RESET<<std::endl;
    }
    else
    {
        std::cout<<MAGENTA<<this->_name<<" attacks "<<target<<" causing "<<this->_attack_damage<<" points of damage"<<RESET<<std::endl;
        this->_energy_points--;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy_points == 0 || this->_hit_points == 0)
    {
        if (this->_hit_points == 0)
            std::cout<<RED<<"Cannot be repaired, "<<this->_name<<" is a useless potato now :("<<RESET<<std::endl;
        else
            std::cout<<RED<<"Cannot be repaired, "<<this->_name<<" has no more energy"<<RESET<<std::endl;
    }
    else if (this->_hit_points == 10)
        std::cout<<MAGENTA<<"No need to repair "<<this->_name<<" as they already have "<<this->_hit_points<<" hit points."<<RESET<<std::endl;
    else
    {
        this->_hit_points += amount;
        if (this->_hit_points > 10)
            this->_hit_points = 10;
        this->_energy_points--;
        std::cout<<MAGENTA<<this->_name<<" received "<<amount<<" hit points."<<RESET<<std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points == 0)
        std::cout<<RED<<this->_name<<" is already dead"<<RESET<<std::endl;
    else
    {
        this->_hit_points -= amount;
        if (this->_hit_points < 0)
            this->_hit_points = 0;
        std::cout<<MAGENTA<<this->_name<<" Was attacked and lost "<<amount<<" hit points."<<RESET<<std::endl;
    }
}

void    ClapTrap::stats(void)const
{
    std::cout<<RED<<this->_name<<RESET<<" have:"<<std::endl;
    std::cout<<GREEN<<this->_hit_points<<RESET<<" hit points"<<std::endl;
    std::cout<<GREEN<<this->_energy_points<<RESET<<" energy points"<<std::endl;
    std::cout<<GREEN<<this->_attack_damage<<RESET<<" attack damage"<<std::endl<<std::endl;
}