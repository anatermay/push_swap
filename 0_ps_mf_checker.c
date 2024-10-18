/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ps_mf_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:20:54 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 17:20:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int print)
{
	if (print != 0)
		write(1, "Error\n", 6);
	exit(1);
}

int	sorted(t_stack *stack_a)
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

int	duplicates(t_stack *stack_a)
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

void	checker(t_stack *stack_a)
{
	if (duplicates(stack_a))
		error(1);
	if (sorted(stack_a))
		error(0);
}

void	valid_numbers(char *str)
{
	long	number;
	int		sign;
	int		index;

	number = 0;
	sign = 1;
	index = 0;
	if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		error(1);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (str[index])
	{
		if (!isdigit(str[index]))
			error(1);
		number = number * 10 + (str[index]) - '0';
		index++;
	}
	if ((number * sign) > INT_MAX || (number * sign) < INT_MIN)
		error(1);
}
