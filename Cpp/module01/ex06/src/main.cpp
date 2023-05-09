/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:54:36 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/02 13:37:27 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main (int argc, char **argv)
{
    Harl harl;

    if (argc < 2)
        std::cout<<RED<<"Please enter an argument"<<std::endl;
    else if (argc > 2)
        std::cout<<RED<<"Too many arguments"<<std::endl;
    else
        harl.complain(argv[1]);
    return (0);
}