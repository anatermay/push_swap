/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:07:47 by aternero          #+#    #+#             */
/*   Updated: 2024/11/22 14:06:00 by aternero         ###   ########.fr       */
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

void	duplicated(t_stack *stack_a)
{
	t_stack	*temp;

	if (!stack_a)
		return ;
	while (stack_a->next != NULL)
	{
		if (stack_a->value == stack_a->next->value)
		{
			free_stack(&stack_a);
			ft_error(1);
		}
		temp = stack_a->next;
		while (temp != NULL)
		{
			if (stack_a->value == temp->value)
			{
				free_stack(&stack_a);
				ft_error(1);
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
}

void	sign_check(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-' && str[index + 1] == '\0')
		ft_error(1);
	if (str[index] == '+' && str[index + 1] == '\0')
		ft_error(1);
}

void	valid_numbers(char *str)
{
	long	number;
	int		sign;
	int		index;

	number = 0;
	sign = 1;
	index = 0;
	sign_check(str);
	if (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+' && str[0] != '"')
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

void	ft_error(bool print)
{
	if (print)
		write(2, "Error\n", 6);
	exit(1);
}
