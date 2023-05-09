/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:50:47 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 18:07:14 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main ()
{
    Zombie *new_zombie = newZombie("Zombie 1");
    randomChump("Zombie 2");
    
    delete new_zombie;
    return(0);
}