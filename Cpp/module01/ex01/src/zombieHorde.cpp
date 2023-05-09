/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:13:25 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/01 18:09:07 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie    *zombieHorde( int N, std::string name )
{
    if (N <= 0)
    {
        std::cout<<"Cannot allocate less than 1 Zombie"<<std::endl;
        return (NULL);
    }
    
    Zombie *zombies = new Zombie[N];

    if (!zombies)
    {
        return (NULL);
        std::cout<<"Allocation failed"<<std::endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
            zombies[i].set_name(name);
    }
    return(zombies);
}
