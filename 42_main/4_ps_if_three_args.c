/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_if_three_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:16:39 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 17:20:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_three_args(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third && second < third)
		sa_sb(stack_a, 1, 0);
	if (first > second && first > third && second > third)
	{
		sa_sb(stack_a, 1, 0);
		rra_rrb(stack_a, 1, 0);
	}
	if (first > second && first > third && second < third)
		ra_rb(stack_a, 1, 0);
	if (first < second && first < third && second > third)
	{
		sa_sb(stack_a, 1, 0);
		ra_rb(stack_a, 1, 0);
	}
	if (first < second && first > third && second > third)
		rra_rrb(stack_a, 1, 0);
}
