/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:33:49 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/09 10:47:40 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string.h>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    //default constructor
        FragTrap(void);
    //string constructor
        FragTrap(std::string name);
    //copy constructor
        FragTrap (const FragTrap &src);
    //assignment operator overload
        FragTrap &operator=(const FragTrap &rh_src);
    //destructor
        ~FragTrap(void);
    //methods
        void    attack(const std::string &target);
        void    highFivesGuys(void);
};

#endif