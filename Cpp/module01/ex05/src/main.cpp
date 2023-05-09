/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:54:36 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/05/02 13:09:18 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main ()
{
    Harl harl;

    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");

    harl.complain("");
    harl.complain("Hello");
    return (0);
}