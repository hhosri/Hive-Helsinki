/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookClass.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:35:19 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/27 11:02:34 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKCLASS_HPP
#define PHONEBOOKCLASS_HPP

#include "ContactClass.hpp"

class PhonebookClass{

	public:
		PhonebookClass(void);
		~PhonebookClass(void);

		void			addContact(ContactClass contact);
		ContactClass 	getContact(int index) const;
		int				getEntriesNum(void) const;

	private:
		ContactClass _contacts[8];
		int			current_idx;
		int			entries;
};

#endif