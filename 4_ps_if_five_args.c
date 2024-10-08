/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_if_five_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:03:23 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 14:05:32 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_five_args(t_stack **stack_a, t_stack **stack_b)
{
	ft_stackadd(stack_b, ft_min_value(stack_a));
	while (ft_stacklength(*stack_a) > 3)
	{
		if ((*stack_b)->position < (ft_stacklength(*stack_a) / 2))
		{
			while ((*stack_b)->position != 0)
			{
				ft_ra_rb(stack_a, 1, 0);
				ft_stackadd(stack_b, ft_min_value(stack_a));
			}
		}
		else if ((*stack_b)->position >= (ft_stacklength(*stack_a) / 2))
		{
			while ((*stack_b)->position != 0)
			{
				ft_rra_rrb(stack_a, 1, 0);
				ft_stackadd(stack_b, ft_min_value(stack_a));			}
		}
		ft_pa_pb(stack_b, stack_a, 1, 1);
	}
	if (ft_sorted(*stack_a) == 0)
		if_three_args(stack_a);
	ft_pa_pb(stack_a, stack_b, 1, 0);
	ft_pa_pb(stack_a, stack_b, 1, 0);
}
