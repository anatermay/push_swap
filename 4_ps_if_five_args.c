/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_if_five_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:03:23 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 13:40:35 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_positioning(t_stack **stack_a)
{
	int	position;
	int	length;

	position = ft_min_position(stack_a);
	length = ft_stacklength(*stack_a);
	if (position <= (length) / 2)
	{
		while (position > 0)
		{
			ft_ra_rb(stack_a, 1, 0);
			position--;
		}
	}
	else if (position > (length) / 2)
	{
		position = length - position + 1;
		while (position > 0)
		{
			ft_rra_rrb(stack_a, 1, 0);
			position--;
		}
	}
} */

void	if_five_args(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = ft_stacklength(*stack_a) - 3;
	while (count > 0)
	{
		ft_positioning(stack_a);
		ft_pa_pb(stack_b, stack_a, 1, 1);
		count--;
	}
	if_four_args(stack_a, stack_b);
	ft_pa_pb(stack_a, stack_b, 1, 0);
}
