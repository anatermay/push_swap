/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_3_turk_algorithm_stack_a.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:40:09 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 22:17:09 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 0);
	pa_pb(stack_a, stack_b, 1, 1);
}

void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target;
	long	best;

	while (stack_b)
	{
		best = LONG_MAX;
		temp = stack_a;
		while (temp)
		{
			if (temp->value > stack_b->value
				&& temp->value < best)
			{
				best = temp->value;
				target = temp;
			}
			temp = temp->next;
		}
		if (best == LONG_MAX)
			stack_b->target->position = min_position(&stack_a);
		else
			stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	init_nodes_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
