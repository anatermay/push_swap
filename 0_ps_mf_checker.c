/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ps_mf_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:23:45 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 18:51:06 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int print)
{
	if (print != 0)
		write(1, "Error\n", 6);
	exit(1);
}

int	ft_sorted(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_duplicates(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = stack_a;
	while (temp != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->value == temp2->value)
				return (1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}

void	ft_checker(t_stack *stack_a)
{
	if (ft_duplicates(stack_a))
		ft_error(1);
	if (ft_sorted(stack_a))
		ft_error(0);
}

void	ft_valid_numbers(char *str)
{
	long	number;
	int		sign;
	int		index;

	number = 0;
	sign = 1;
	index = 0;
	if (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		ft_error(1);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			ft_error(1);
		number = number * 10 + (str[index]) - '0';
		index++;
	}
	if ((number * sign) > INT_MAX || (number * sign) < INT_MIN)
		ft_error(1);
}
