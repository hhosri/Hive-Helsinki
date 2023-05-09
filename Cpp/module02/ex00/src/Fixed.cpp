/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:25:04 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/04 11:06:58 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout<<"Default constructor called"<<std::endl;
    this->_fixed_point = 0;
    return;
}

Fixed::Fixed (const Fixed &source)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = source;
    return;
}

Fixed&  Fixed::operator=(const Fixed &source)
{
    std::cout<<"Copy assignement operator called"<<std::endl;
    if (this != &source)
        this->_fixed_point = source.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
    return;
}

int Fixed::getRawBits (void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called"<<std::endl;
    this->_fixed_point = raw;
    return;
}













// Fixed::Fixed(void)
// {
//     std::cout<<"Default Constructor called"<<std::endl;
//     this->_fixed_point = 0;
//     return;
// }

// Fixed::Fixed(const Fixed &source)
// {
//     std::cout<<"Copy Constructor called"<<std::endl;
//     *this = source;
//     return;
// }

// Fixed& Fixed::operator=(const Fixed &source)
// {
//     std::cout<<"Copy assignment operator called"<<std::endl;
//     if (this != &source)
//         this->_fixed_point = source.getRawBits();
//     return (*this);
// }

// Fixed::~Fixed(void)
// {
//     std::cout<<"Destructor called"<<std::endl;
//     return;
// }

// int Fixed::getRawBits(void) const
// {
//     std::cout<<"getRawBits member function called"<<std::endl;
//     return (this->_fixed_point);
// }

// void Fixed::setRawBits(int const raw)
// {
//     std::cout<<"setRawBits member function called"<<std::endl;
//     this->_fixed_point = raw;
//     return;
// }
