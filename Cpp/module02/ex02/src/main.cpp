/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:38:13 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/05 13:42:11 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

#include <iostream>
int main( void ) 
{
    { 
        std::cout<<RED<<"*****TEST 1*****"<<RESET<<std::endl;
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl<<std::endl;
    }
    {   
        std::cout<<RED<<"*****TEST 2*****"<<RESET<<std::endl;
        Fixed a(1.5f);
        Fixed b(2.5f);

        std::cout<<GREEN<< "a:" <<RESET<<std::endl;
        std::cout<< a <<std::endl<<std::endl;

        std::cout<<GREEN<< "b:" <<RESET<<std::endl;
        std::cout<< b <<std::endl<<std::endl;

        std::cout<<GREEN<< "a < b:" <<RESET<<std::endl;
        std::cout<< (a < b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a > b:" <<RESET<<std::endl;
        std::cout<< (a > b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a <= b:" <<RESET<<std::endl;
        std::cout<< (a <= b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a >= b:" <<RESET<<std::endl;
        std::cout<< (a >= b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a == b:" <<RESET<<std::endl;
        std::cout<< (a == b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a != b:" <<RESET<<std::endl;
        std::cout<< (a != b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a + b:" <<RESET<<std::endl;
        std::cout<< (a + b) <<std::endl<<std::endl;


        std::cout<<GREEN<< "a - b:" <<RESET<<std::endl;
        std::cout<< (a - b) <<std::endl<<std::endl;


        std::cout<<GREEN<< "a * b:" <<RESET<<std::endl;
        std::cout<< (a * b) <<std::endl<<std::endl;


        std::cout<<GREEN<< "a / b:" <<RESET<<std::endl;
        std::cout<< (a / b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a++:" <<RESET<<std::endl;
        std::cout<< (a++) <<std::endl;
        std::cout<<GREEN<< "a after ++:" <<RESET<<std::endl;
        std::cout<< (a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "++a:" <<RESET<<std::endl;
        std::cout<< (++a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a--:" <<RESET<<std::endl;
        std::cout<< (a--) <<std::endl;
        std::cout<<GREEN<< "a after --:" <<RESET<<std::endl;
        std::cout<< (a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "--a:" <<RESET<<std::endl;
        std::cout<< (--a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "find min:" <<RESET<<std::endl;
        std::cout<< a.min(a, b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "find max:" <<RESET<<std::endl;
        std::cout<< b.max(a, b) <<std::endl<<std::endl;


        return 0;   
    }
}

