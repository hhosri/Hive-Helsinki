/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:15:01 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/05 13:54:21 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define RED    "\033[0;31m"
#define RESET "\033[0m"
#define GREEN  "\033[0;32m"

class Fixed
{
    public:
        //Constructors
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        //Copy-copy Assignment
        Fixed (const Fixed &source);
        Fixed& operator=(const Fixed &rh);
        //member functs
        float   toFloat(void) const;
        int     toInt(void) const;
        //get-set
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        //Comparison
        bool operator>(Fixed &rh) const;
        bool operator<(Fixed &rh) const;
        bool operator>=(Fixed &rh) const;
        bool operator<=(Fixed &rh) const;
        bool operator==(Fixed &rh) const;
        bool operator!=(Fixed &rh) const;
        //Arithmetic
        float operator+(const Fixed &rh) const;
        float operator-(const Fixed &rh) const;
        float operator/(const Fixed &rh) const;
        float operator*(const Fixed &rh) const;
        //inc - dec
        // pre
		Fixed operator++();
		Fixed operator--();
		// post
		Fixed operator++(int);
		Fixed operator--(int);
        //min-max
        static Fixed &min(Fixed &num1, Fixed &num2);
        static Fixed &max(Fixed &num1, Fixed &num2);
        static const Fixed &min(Fixed const &num1, Fixed const &num2);
        static const Fixed &max(Fixed const &num1, Fixed const &num2);
        //Destructor
        ~Fixed(void);
        
    private:
        int                 _fixed_point;
        static const int    _fract_bits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed); 

#endif
