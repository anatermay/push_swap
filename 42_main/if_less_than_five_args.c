/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_less_than_five_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:53:23 by aternero          #+#    #+#             */
/*   Updated: 2024/10/30 12:08:12 by aternero         ###   ########.fr       */
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

void	if_four_args(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = stacklength(*stack_a) - 3;
	while (count > 0)
	{
		min_positioning(stack_a);
		pa_pb(stack_b, stack_a, 1, 1);
		count--;
	}
	if_three_args(stack_a);
	pa_pb(stack_a, stack_b, 1, 0);
}

void	if_five_args(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = stacklength(*stack_a) - 3;
	while (count > 0)
	{
		min_positioning(stack_a);
		pa_pb(stack_b, stack_a, 1, 1);
		count--;
	}
	if_four_args(stack_a, stack_b);
	pa_pb(stack_a, stack_b, 1, 0);
}
