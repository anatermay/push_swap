/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_1_inversed_sorting_algorithm.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 21:49:15 by aternero         ###   ########.fr       */
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
