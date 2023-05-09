/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:08:12 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 11:47:50 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon{

    public:
        Weapon(std::string type);
        ~Weapon(void);
        const std::string &getType(void) const;
        void        setType(std::string new_type);
    private:
        std::string _type;
};

#endif
