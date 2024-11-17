/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:07:47 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 17:12:00 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted(t_stack *stack_a)
{
	t_stack	*temp;

	if (!stack_a)
		return (1);
	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

bool	duplicates(t_stack *stack_a)
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

void	stack_args_checker(t_stack *stack)
{
	if (!stack)
		return ;
	if (sorted(stack) == 1)
		error(0);
	if (duplicates(stack) == 1)
		error(1);
}

void	valid_numbers(char *str)
{
	long	number;
	int		sign;
	int		index;

	number = 0;
	sign = 1;
	index = 0;
	if (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+')
		error(1);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			error(1);
		number = number * 10 + (str[index]) - '0';
		index++;
	}
	if ((number * sign) > INT_MAX || (number * sign) < INT_MIN)
		error(1);
}

void	error(bool print)
{
	if (print)
		write(2, "Error\n", 6);
	exit(1);
}
