/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:39:51 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/02 15:52:38 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"


int main ()
{
    int size = 5;
    Zombie  *zombies = zombieHorde(size, "Mr Zombie");

    for (int i = 0; i < size; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}