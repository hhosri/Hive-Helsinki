/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:08:47 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/10 17:21:49 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	disable_characters(int toggle)
{
	struct termios	term;

	if (!toggle)
	{
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag &= ~ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
	if (toggle)
	{
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag |= ECHOCTL;
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
}
