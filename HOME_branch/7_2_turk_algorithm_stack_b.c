/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_2_turk_algorithm_stack_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:14:20 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 22:18:31 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->side == 1 && cheapest->target->side == 1)
		rr(stack_a, stack_b, 1);
	else if (cheapest->side == 0
		&& cheapest->target->side == 0)
		rrr(stack_a, stack_b, 1);
	prep_for_push(stack_a, cheapest, 0);
	prep_for_push(stack_b, cheapest->target, 1);
	pa_pb(stack_b, stack_a, 1, 1);
}

void	set_target_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target;
	long	best;

	while (stack_a)
	{
		temp = stack_b;
		best = LONG_MIN;
		while (temp)
		{
			if (temp->value < stack_a->value && temp->value > best)
			{
				best = temp->value;
				target = temp;
			}
			temp = temp->next;
		}
		if (best == LONG_MIN)
			stack_a->target->position = max_position(&stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = stacklength(stack_a);
	length_b = stacklength(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->position;
		if (stack_a->side == 0)
			stack_a->cost = length_a - stack_a->position;
		if (stack_a->target->side == 1)
			stack_a->cost += stack_a->target->position;
		else
			stack_a->cost += (length_b - stack_a->target->position);
		stack_a = stack_a->next;
	}
}

void	init_nodes_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_stack_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
