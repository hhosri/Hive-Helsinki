/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:27:20 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 12:53:38 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA{

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void) const;
    private:
        Weapon      &_weapon;
        std::string _name;
};

#endif