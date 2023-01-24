/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hosr <hel-hosr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:15:43 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/01/02 17:23:41 by hel-hosr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_dup(int position, char **input)
{
	int	i;
	int	j;

	i = position;
	while (input[i])
	{	
		j = i + 1;
		while (input[j])
		{
			if (ft_atoi(input[i]) != ft_atoi(input[j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_is_int(int position, char **input)
{
	int	i;

	i = position;
	while (input[i])
	{
		if (!(ft_atoi_zero(input[i])) && !(ft_is_zero(input[i])))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_num(int position, char **input)
{
	int	i;
	int	j;

	i = position;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (ft_isdigit(input[i][j]))
				j++;
			else if ((input[i][j] == '-' || input[i][j] == '+')
				&& ft_isdigit(input[i][j + 1]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_input(int position, char **input)
{
	if (!(ft_is_num(position, input)))
		return (0);
	if (!(ft_is_int(position, input)))
		return (0);
	if (!(ft_is_dup(position, input)))
		return (0);
	return (1);
}
