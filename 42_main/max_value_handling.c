/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_more_ina_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:20:10 by aternero          #+#    #+#             */
/*   Updated: 2024/10/28 12:21:26 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
