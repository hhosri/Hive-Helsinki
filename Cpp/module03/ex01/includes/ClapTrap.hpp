/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:40:48 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/09 10:27:10 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define BLUE   "\033[0;34m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define CYAN   "\033[0;36m"
#define WHITE  "\033[1;37m"
#define GRAY   "\033[1;30m"
#define BLACK  "\033[0;30m"
#define DARK_RED   "\033[1;31m"
#define DARK_GREEN "\033[1;32m"
#define DARK_BLUE  "\033[1;34m"
#define DARK_GRAY  "\033[1;30m"
#define RESET "\033[0m"

class ClapTrap
{

    public:
    //default constructor
        ClapTrap(void);
    //string constructor
        ClapTrap(std::string name);
    //copy constructor
        ClapTrap (const ClapTrap &src);
    //assignment operator overload
        ClapTrap &operator=(const ClapTrap &rh_src);
    //destructor
        ~ClapTrap(void);

    //get-set
        void    set_hit_points(int value);
        void    set_energy_points(int value);
        void    set_attack_damage(int value);

        int         get_hit_points(void) const;
        int         get_energy_points(void) const;
        int         get_attack_damage(void) const;
        std::string get_name(void) const;

    //member functions
        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

    //extra function for easier testing
        void    stats(void)const;
    protected:
        std::string _name;
        int         _hit_points;
        int         _energy_points;
        int         _attack_damage;

};

#endif
