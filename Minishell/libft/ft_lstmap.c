/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:44:22 by corellan          #+#    #+#             */
/*   Updated: 2023/01/13 14:02:05 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*temp;
	t_list	*iter;

	iter = lst;
	copy = (void *)0;
	temp = (void *)0;
	while (iter != (void *)0)
	{
		temp = ft_lstnew((*f)(iter->content));
		if (temp == (void *)0)
		{
			ft_lstclear(&copy, del);
			return (0);
		}
		ft_lstadd_back(&copy, temp);
		iter = iter->next;
		temp = temp->next;
	}
	return (copy);
}
