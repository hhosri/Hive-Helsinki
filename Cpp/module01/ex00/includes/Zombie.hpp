/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:46:52 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/28 11:39:47 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

    public:
        Zombie(std::string name);
        ~Zombie(void);
        void announce(void);
        
    private:
        std::string _name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif