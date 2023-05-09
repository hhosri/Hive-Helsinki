/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:03:48 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 11:26:15 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "PhonebookClass.hpp"
#include "ContactClass.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define REGULAR "\033[0m"

ContactClass	create_contact();
void			display_all(PhonebookClass phonebook);
void			prompt_one(PhonebookClass phonebook);
void			display_empty(void);
void			display_user(PhonebookClass phonebook, int index);
int				is_valid_num(std::string str);
#endif