/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_min_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 22:06:26 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_node(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	temp->value = min_value(stack);
	temp->position = min_position(stack);
	return (temp);
}

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
			ra_rb(stack, 1, 0);
			position--;
		}
	}
	else if (position > (length) / 2)
	{
		position = length - position;
		while (position > 0)
		{
			rra_rrb(stack, 1, 0);
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

	temp = *stack;
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

int	min_value(t_stack **stack)
{
	t_stack	*temp;
	int		min_value;

	temp = *stack;
	min_value = temp->value;
	while (temp != NULL)
	{
		if (temp->value < min_value)
			min_value = temp->value;
		temp = temp->next;
	}
	return (min_value);
}
