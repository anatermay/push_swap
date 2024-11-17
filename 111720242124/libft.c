/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:27 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 14:05:22 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	spc(char str)
{
	if (str == ' ' || str == '\t')
		return (1);
	if (str == '\n' || str == '\v')
		return (1);
	if (str == '\f' || str == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0' && !(ft_isdigit(str[i])) && spc(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	return (result * sign);
}
