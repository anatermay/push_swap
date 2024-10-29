/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_0_turk_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 22:13:14 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (stacklength(*stack_a) > 3 && sorted(*stack_a) == 0)
		pa_pb(stack_b, stack_a, 1, 1);
	if (stacklength(*stack_a) > 3 && sorted(*stack_a) == 0)
		pa_pb(stack_b, stack_a, 1, 1);
	while (stacklength(*stack_a) > 3 && sorted(*stack_a) == 0)
	{
		init_nodes_stack_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	if_three_args(stack_a);
	while (*stack_b)
	{
		init_nodes_stack_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_positioning(stack_a);
}
