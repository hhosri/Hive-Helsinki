/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:37:13 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/08 16:50:25 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    //default constructor
        ScavTrap(void);
    //string constructor
        ScavTrap(std::string name);
    //copy constructor
        ScavTrap (const ScavTrap &src);
    //assignment operator overload
        ScavTrap &operator=(const ScavTrap &rh_src);
    //destructor
        ~ScavTrap(void);
    //methods
        void    attack(const std::string &target);
        void    guardGate(void);
};

#endif