/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_more_ina.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:37:56 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 13:43:25 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_positioning(t_stack **stack_a)
{
	int	position;
	int	length;

	position = ft_min_position(stack_a);
	length = ft_stacklength(*stack_a);
	if (position <= (length) / 2)
	{
		while (position > 0)
		{
			ft_ra_rb(stack_a, 1, 0);
			position--;
		}
	}
	else if (position > (length) / 2)
	{
		position = length - position;
		while (position > 0)
		{
			ft_rra_rrb(stack_a, 1, 0);
			position--;
		}
	}
}

int	ft_min_position(t_stack **stack_a)
{
	t_stack	*temp;
	int		min_value;
	int		position;
	int		min_position;

	temp = *stack_a;
	min_value = temp->value;
	position = 0;
	min_position = 0;
	while (temp != NULL)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_position = position;
		}
		temp = temp->next;
		position++;
	}
	return (min_position);
}

int	ft_min_value(t_stack **stack_a)
{
	t_stack	*temp;
	int		min_value;

	temp = *stack_a;
	min_value = temp->value;
	while (temp != NULL)
	{
		if (temp->value < min_value)
			min_value = temp->value;
		temp = temp->next;
	}
	return (min_value);
}

int	ft_max_position(t_stack **stack_a)
{
	t_stack	*temp;
	int		max_value;
	int		position;
	int		max_position;

	temp = *stack_a;
	max_value = temp->value;
	position = 0;
	max_position = 0;
	while (temp != NULL)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			max_position = position;
		}
		temp = temp->next;
		position++;
	}
	return (max_position);
}

int	ft_max_value(t_stack **stack_a)
{
	t_stack	*temp;
	int		max_value;

	temp = *stack_a;
	max_value = temp->value;
	while (temp != NULL)
	{
		if (temp->value > max_value)
			max_value = temp->value;
		temp = temp->next;
	}
	return (max_value);
}
