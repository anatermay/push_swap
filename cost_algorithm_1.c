/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:12:29 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 19:19:53 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_calculator(t_stack **a, int index, int target, int position)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->index > index && temp->index < target)
		{
			target = temp->index;
			position = temp->position;
		}
		temp = temp->next;
	}
	if (target != INT_MAX)
		return (position);
	temp = *a;
	while (temp)
	{
		if (temp->index < target)
		{
			target = temp->index;
			position = temp->position;
		}
		temp = temp->next;
	}
	return (position);
}

void	target_assignment(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		position;

	temp = *b;
	position_assignment(a);
	position_assignment(b);
	position = 0;
	while (temp)
	{
		position = target_calculator(a, temp->index, INT_MAX, position);
		temp->target = position;
		temp = temp->next;
	}
	free_stack(&temp);
}

void	position_assignment(t_stack **stack)
{
	t_stack	*temp;
	int		position;

	temp = *stack;
	position = 0;
	while (temp)
	{
		temp->position = position;
		temp = temp->next;
		position++;
	}
	free_stack(&temp);
}

int	index_calculator(t_stack *stack, int value)
{
	int	index;

	index = 1;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

void	index_assignment(t_stack **stack_a)
{
	t_stack	*dup;
	t_stack	*original;
	t_stack	*temp;

	dup = stackdup(*stack_a);
	bubble_sort(&dup);
	original = *stack_a;
	while (original)
	{
		original->index = index_calculator(dup, original->value);
		original = original->next;
	}
	while (dup)
	{
		temp = dup;
		dup = dup->next;
		free(temp);
	}
}
