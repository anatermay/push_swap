/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_if_four_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:00:22 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 14:33:23 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_four_args(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = ft_stacklength(*stack_a) - 3;
	while (count > 0)
	{
		ft_positioning(stack_a);
		ft_pa_pb(stack_b, stack_a, 1, 1);
		count--;
	}
	if_three_args(stack_a);
	ft_pa_pb(stack_a, stack_b, 1, 0);
}
