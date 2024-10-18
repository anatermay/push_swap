/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_algorithm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:27:02 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 17:29:32 by aternero         ###   ########.fr       */
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

void	ps_algorithm(t_stack **stack_a, t_stack **stack_b)
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
	else
		cost_algorithm(stack_a, stack_b);
}
