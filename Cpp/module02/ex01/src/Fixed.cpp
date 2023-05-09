/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:17:11 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/04 15:15:47 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

//Consructors
Fixed::Fixed(void)
{
    std::cout<<"Default constructor is called"<<std::endl;
    this->_fixed_point = 0;
    return;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int Constructor called" << std::endl;
    this->_fixed_point = num << this->_fract_bits; 
    return;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float Constructor called" << std::endl;
	this->_fixed_point = roundf(num * (1 << this->_fract_bits)); 
    return;
}
//Copy-Copy assignment
Fixed::Fixed(const Fixed &source)
{
    std::cout<<"Copy constructor is called"<<std::endl;
    *this = source;
    return;
}

Fixed& Fixed::operator=(const Fixed &source)
{
    std::cout<<"Copy assignment operator is called"<<std::endl;
    if (this != &source)
        this->_fixed_point = source.getRawBits();
    return (*this);
}

//member functs
float	Fixed::toFloat(void)const
{
	return ((float)this->_fixed_point / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fixed_point >> this->_fract_bits);
}

// get - set
int	Fixed::getRawBits(void)const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
    return;
}

//Destructor
Fixed::~Fixed(void)
{
    std::cout<<"Destructor is called"<<std::endl;
    return;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &object)
{
	output << object.toFloat();
	return (output);
}