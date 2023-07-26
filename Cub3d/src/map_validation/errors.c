/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kakumar <kakumar@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:11:15 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/07/19 10:54:11 by kakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_error_exit(char *msg, int success_status)
{
	int	msg_len;

	msg_len = ft_strlen(msg);
	write(2, "Error\n", 6);
	write(2, msg, msg_len);
	if (success_status == 0)
		exit(EXIT_FAILURE);
	else if (success_status == 1)
		exit(EXIT_SUCCESS);
}
