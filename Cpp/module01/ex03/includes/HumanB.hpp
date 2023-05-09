/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:27:34 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 12:57:31 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB{

    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    attack(void) const;
        void    setWeapon(Weapon &weapon);
    private:
        Weapon      *_weapon;
        std::string _name;
};

#endif