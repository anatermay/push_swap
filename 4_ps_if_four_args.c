/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_if_four_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:00:22 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 18:50:21 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_four_args(t_stack **stack_a, t_stack **stack_b)
{
	ft_stackadd(stack_b, ft_min_value(stack_a));
	if ((*stack_b)->position < 2)
	{
		while ((*stack_b)->position == 0)
			ft_ra_rb(stack_a, 1, 0);
	}
	else if (((*stack_b)->position) >= 2)
	{
		while ((*stack_b)->position == 0)
			ft_rra_rrb(stack_a, 1, 0);
	}
	ft_pa_pb(stack_a, stack_b, 1, 1);
	if_three_args(stack_a);
	ft_pa_pb(stack_a, stack_b, 1, 0);
}

