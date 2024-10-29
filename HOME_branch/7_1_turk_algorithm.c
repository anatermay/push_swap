/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_1_turk_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:23:19 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 22:13:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top, int aorb)
{
	while (*stack != top)
	{
		if (aorb == 0)
		{
			if (top->side)
				ra_rb(stack, 1, 0);
			else
				rra_rrb(stack, 1, 0);
		}
		else if (aorb == 1)
		{
			if (top->side)
				ra_rb(stack, 1, 1);
			else
				rra_rrb(stack, 1, 1);
		}
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	current_index(t_stack *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
		return ;
	median = stacklength(stack) / 2;
	while (stack)
	{
		stack->position = index;
		if (index <= median)
			stack->side = 0;
		else
			stack->side = 1;
		stack = stack->next;
		index++;
	}
}
