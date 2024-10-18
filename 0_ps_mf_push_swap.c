/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ps_mf_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:27:21 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 18:08:20 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_prev_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (if_inversely_sorted(stack_a))
		sort_inversed(stack_a, stack_b);
	else if (if_partially_sorted(stack_a))
		min_positioning(stack_a);
	else if (if_partially_and_inversely_sorted(stack_a))
	{
		sort_inversed(stack_a, stack_b);
		min_positioning(stack_a);
	}
	stack_reset(stack_a, stack_b);
	/* else if (stacklength(*stack_a) < 5
		&& stacklength(*stack_a) <= 100)
		cost_algorithm(stack_a, stack_b); */
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	length;

	stack_b = NULL;
	length = stacklength(stack_a);
	if (length == 2 && sorted(stack_a) == 0)
		sa_sb(&stack_a, 1, 0);
	else if (length == 3 && sorted(stack_a) == 0)
		if_three_args(&stack_a);
	else if (length == 4 && sorted(stack_a) == 0)
		if_four_args(&stack_a, &stack_b);
	else if (length == 5 && sorted(stack_a) == 0)
		if_five_args(&stack_a, &stack_b);
	else if (length > 5 && sorted(stack_a) == 0)
		ps_prev_algorithm(&stack_a, &stack_b);
}
