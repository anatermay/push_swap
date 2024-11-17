/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:27 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 19:22:49 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_positioning(t_stack **stack)
{
	int	position;
	int	length;

	position = min_position(stack);
	length = stacklength(*stack);
	if (position <= (length) / 2)
	{
		while (position > 0)
		{
			ra(stack, 1);
			position--;
		}
	}
	else if (position > (length) / 2)
	{
		position = length - position;
		while (position > 0)
		{
			rra(stack, 1);
			position--;
		}
	}
}

int	min_position(t_stack **stack)
{
	t_stack	*temp;
	int		min_value;
	int		position;
	int		min_position;

	if (!stack || !*stack)
		return (-1);
	min_value = INT_MAX;
	temp = *stack;
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

int	max_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}
