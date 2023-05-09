/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:56:17 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/02 13:15:19 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define BLUE   "\033[0;34m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define CYAN   "\033[0;36m"
#define WHITE  "\033[1;37m"
#define GRAY   "\033[1;30m"
#define BLACK  "\033[0;30m"
#define DARK_RED   "\033[1;31m"
#define DARK_GREEN "\033[1;32m"
#define DARK_BLUE  "\033[1;34m"
#define DARK_GRAY  "\033[1;30m"
#define RESET "\033[0m"


class Harl{

    public:
        Harl (void);
        ~Harl (void);
        void    complain( std::string level )const;

    private:
        void    _debug(void) const;
        void    _info(void) const;
        void    _warning(void) const;
        void    _error(void) const;

};

#endif

