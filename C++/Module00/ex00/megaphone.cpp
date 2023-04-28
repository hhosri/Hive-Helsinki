/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:06 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/25 16:35:07 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    char    c;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                c = std::toupper(argv[i][j]);
                std::cout << c;
            }
            if (i != (argc - 1))
                std::cout << " " ;
        }
        std::cout << std::endl;
    }
    return (0);
}
