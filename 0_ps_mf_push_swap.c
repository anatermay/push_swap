/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_algorithm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:27:02 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 20:08:39 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_inversed(t_stack **stack_a, t_stack **stack_b)
{
	int		length;
	
	length = ft_stacklength(*stack_a);
	while (length > 0)
	{
		ft_pa_pb(stack_b, stack_a, 1, 1);
		length--;
	}
	length = ft_stacklength(*stack_b);
	while (length > 0)
	{
		ft_rra_rrb(stack_b, 1, 1);
		ft_pa_pb(stack_a, stack_b, 1, 0);
		length--;
	}
}

void	ps_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (if_inversely_sorted(stack_a))
		ft_sort_inversed(stack_a, stack_b);
	else if (if_partially_sorted(stack_a))
		ft_positioning(stack_a);
	else if (if_partially_and_inversely_sorted(stack_a))
	{
		ft_sort_inversed(stack_a, stack_b);
		ft_positioning(stack_a);
	}
	else
		turk_algorithm(stack_a, stack_b);
}
