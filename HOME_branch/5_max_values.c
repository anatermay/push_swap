/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_max_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 22:06:13 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_node(t_stack **stack)
{
	t_stack	*temp;

	temp = NULL;
	temp->value = max_value(stack);
	temp->position = max_position(stack);
	return (temp);
}

void	max_positioning(t_stack **stack)
{
	int	position;
	int	length;

	position = max_position(stack);
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

int	max_position(t_stack **stack)
{
	t_stack	*temp;
	int		max_value;
	int		position;
	int		max_position;

	temp = *stack;
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

int	max_value(t_stack **stack)
{
	t_stack	*temp;
	int		max_value;

	temp = *stack;
	max_value = temp->value;
	while (temp != NULL)
	{
		if (temp->value > max_value)
			max_value = temp->value;
		temp = temp->next;
	}
	return (max_value);
}
