/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zzz_cost_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:47:24 by aternero          #+#    #+#             */
/*   Updated: 2024/10/28 10:58:43 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_calculator(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	target;

	position = 0;
	target = 0;
	while (*stack_b)
	{
		(*stack_b)->position = position;
		while (*stack_a)
		{
			if ((*stack_b)->value < (*stack_a)->value
				&& (*stack_b)->value > (*stack_a)->next->value)
			{
				(*stack_b)->target = (*stack_a)->next->position;
				if (position <= (stacklength(*stack_b) / 2))
				{
					if (target <= (stacklength(*stack_a) / 2))
					{
						(*stack_b)->cost = (*stack_b)->position + (*stack_b)->target + 1;
						(*stack_b)->t_side = 0;
					}
					else
					{
						(*stack_b)->cost = (*stack_b)->position + stacklength(*stack_a) - (*stack_b)->target + 1;
						(*stack_b)->t_side = 1;
					}
					(*stack_b)->p_side = 0;
				}
				else
				{
					if (target <= (stacklength(*stack_a) / 2))
					{
						(*stack_b)->cost = stacklength(*stack_b) - (*stack_b)->position + (*stack_b)->target + 1;
						(*stack_b)->t_side = 0;
					}
					else
					{
						(*stack_b)->cost = stacklength(*stack_b) - (*stack_b)->position + stacklength(*stack_a) - (*stack_b)->target + 1;
						(*stack_b)->t_side = 1;
					}
					(*stack_b)->p_side = 1;
				}
				(*stack_a) = (*stack_a)->next;
			}
			(*stack_a) = (*stack_a)->next;
		}
		position++;
		(*stack_b) = (*stack_b)->next;
	}
}

/* t_stack	*min_cost_searcher(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*min_cost;

	return (min_cost);
} */

void	best_movement_calculator(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		min_cost;
	int		position[2];
	int		target[2];

	position[0]= 0;
	target[0]= 0;
	
	cost_calculator(stack_a, stack_b);
	temp = *stack_b;
	min_cost = INT_MAX;
	while (temp)
	{
		if (temp->cost < min_cost)
		{
			min_cost = temp->cost;
			position[0]= temp->position;
			if (position[0] <= (stacklength(*stack_b) / 2))
				position[1] = 0;
			else
				position[1] = 1;
			target[0]= temp->target;
			if (target[0] <= (stacklength(*stack_a) / 2))
				target[1] = 0;
			else
				target[1] = 1;
		}
		temp = temp->next;
	}
	printf("hello\n");
	if (position[1] == 0 && target[1] == 0)
	{
		while (position[0]-- > 0 || target[0]-- > 0)
			rr(stack_a, stack_b, 1);
		while (position[0]-- > 0)
			ra_rb(stack_b, 1, 1);
		while (target[0]-- > 0)
			ra_rb(stack_a, 1, 0);
	}
	else if (position[1] == 0 && target[1] == 1)
	{
		while (position[0]-- > 0)
			ra_rb(stack_b, 1, 1);
		while (target[0]> 0)
			rra_rrb(stack_a, 1, 0);
	}
	else if (position[1] == 1 && target[1] == 0)
	{
		while (position[0]-- > 0)
			rra_rrb(stack_b, 1, 1);
		while (target[0]> 0)
			ra_rb(stack_a, 1, 0);
	}
	else if (position[1] == 1 && target[1] == 1)
	{
		while (position[0]-- > 0 || target[0]-- > 0)
			rrr(stack_a, stack_b, 1);
		while (position[0]-- > 0)
			rra_rrb(stack_b, 1, 1);
		while (target[0]> 0)
			rra_rrb(stack_a, 1, 0);
	}
	pa_pb(stack_a, stack_b, 1, 0);
}
