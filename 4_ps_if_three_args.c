/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_if_(*stack_a)->next->next->value_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:22:52 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 14:25:03 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_three_args(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value)
		ft_sa_sb(stack_a, 1, 0);
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			ft_sa_sb(stack_a, 1, 0);
			ft_rra_rrb(stack_a, 1, 0);
		}
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value
		&& (*stack_a)->next->value < (*stack_a)->next->next->value)
		ft_ra_rb(stack_a, 1, 0);
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value < (*stack_a)->next->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		ft_sa_sb(stack_a, 1, 0);
		ft_ra_rb(stack_a, 1, 0);
	}
	else if ((*stack_a)->value < (*stack_a)->next->value
		&& (*stack_a)->value > (*stack_a)->next->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
		ft_rra_rrb(stack_a, 1, 0);
}
