/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:17:11 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/05 13:30:31 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

//Consructors--------------------------------------------------
Fixed::Fixed(void)
{
    // std::cout<<"Default constructor is called"<<std::endl;
    this->_fixed_point = 0;
    return;
}

Fixed::Fixed(const int num)
{
    // std::cout << "Int Constructor called" << std::endl;
    this->_fixed_point = num << this->_fract_bits; 
    return;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float Constructor called" << std::endl;
	this->_fixed_point = roundf(num * (1 << this->_fract_bits)); 
    return;
}
//Copy-Copy assignment--------------------------------------------------
Fixed::Fixed(const Fixed &source)
{
    // std::cout<<"Copy constructor is called"<<std::endl;
    *this = source;
    return;
}

Fixed& Fixed::operator=(const Fixed &rh)
{
    // std::cout<<"Copy assignment operator is called"<<std::endl;
    if (this != &rh)
        this->_fixed_point = rh.getRawBits();
    return (*this);
}

//member functs--------------------------------------------------
float	Fixed::toFloat(void)const
{
	return ((float)this->_fixed_point / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fixed_point >> this->_fract_bits);
}

// get - set--------------------------------------------------
int	Fixed::getRawBits(void)const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
    return;
}
//Comparison--------------------------------------------------
bool Fixed::operator>(Fixed &rh) const
{
    return(this->getRawBits() > rh.getRawBits());
}

bool Fixed::operator<(Fixed &rh) const
{
    return(this->getRawBits() < rh.getRawBits());
}

bool Fixed::operator>=(Fixed &rh) const
{
    return(this->getRawBits() >= rh.getRawBits());
}

bool Fixed::operator<=(Fixed &rh) const
{
    return(this->getRawBits() <= rh.getRawBits());
}

bool Fixed::operator==(Fixed &rh) const
{
    return(this->getRawBits() == rh.getRawBits());
}

bool Fixed::operator!=(Fixed &rh) const
{
    return(this->getRawBits() != rh.getRawBits());
}

//Arithmetic--------------------------------------------------
float Fixed::operator+(const Fixed &rh) const
{
    return(this->toFloat() + rh.toFloat());    
}

float Fixed::operator-(const Fixed &rh) const
{
    return(this->toFloat() - rh.toFloat());    
}

float Fixed::operator/(const Fixed &rh) const
{
    return(this->toFloat() / rh.toFloat());    
}

float Fixed::operator*(const Fixed &rh) const
{
    return(this->toFloat() * rh.toFloat());    
}
//inc-dec--------------------------------------------------
//PRE--------------------------------------------------
Fixed Fixed::operator++()
{
    this->_fixed_point++;
    return(*this);
}

Fixed Fixed::operator--()
{
    this->_fixed_point--;
    return(*this);
}

//POST--------------------------------------------------
Fixed Fixed::operator++(int)
{
    Fixed temp;
    temp._fixed_point = this->_fixed_point;
    ++this->_fixed_point;
    return(temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp;
    temp._fixed_point = this->_fixed_point;
    --this->_fixed_point;
    return(temp);
}
//MIN-MAX--------------------------------------------------

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
    if (num1.getRawBits() <= num2.getRawBits())
        return(num1);
    else
        return(num2);
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
    if (num1.getRawBits() >= num2.getRawBits())
        return(num1);
    else
        return(num2);
}

const Fixed& Fixed::min(Fixed const &num1, Fixed const &num2)
{
    if (num1.getRawBits() <= num2.getRawBits())
        return(num1);
    else
        return(num2);
}

const Fixed& Fixed::max(Fixed const &num1, Fixed const &num2)
{
    if (num1.getRawBits() >= num2.getRawBits())
        return(num1);
    else
        return(num2);
}




//Destructor--------------------------------------------------
Fixed::~Fixed(void)
{
    // std::cout<<"Destructor is called"<<std::endl;
    return;
}

std::ostream	&operator<<(std::ostream &output, Fixed const &object)
{
	output << object.toFloat();
	return (output);
}