/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:46:52 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/28 14:39:45 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

    public:
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
        void    set_name(std::string name);
        
    private:
        std::string _name;

};

Zombie*    zombieHorde( int N, std::string name );

#endif
