/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ps_mf_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:27:21 by aternero          #+#    #+#             */
/*   Updated: 2024/10/28 14:05:10 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_inversed(t_stack **stack_a, t_stack **stack_b)
{
	int		length;

	length = stacklength(*stack_a);
	while (length > 0)
	{
		pa_pb(stack_b, stack_a, 1, 1);
		length--;
	}
	length = stacklength(*stack_b);
	while (length > 0)
	{
		rra_rrb(stack_b, 1, 1);
		pa_pb(stack_a, stack_b, 1, 0);
		length--;
	}
}

void	ps_prev_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	/* if (if_inversely_sorted(stack_a))
		sort_inversed(stack_a, stack_b);
	else if (if_partially_sorted(stack_a))
		min_positioning(stack_a);
	else if (if_partially_and_inversely_sorted(stack_a))
	{
		sort_inversed(stack_a, stack_b);
		min_positioning(stack_a);
	} */
	if (stacklength(*stack_a) > 5)
		algorithm(stack_a, stack_b);
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
