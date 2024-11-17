/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_nbr_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:27 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 19:23:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_sorting(t_stack **stack_a)
{
	int		max;

	if (sorted(*stack_a))
		return ;
	max = max_index(*stack_a);
	if ((*stack_a)->index == max)
		ra(stack_a, 1);
	else if ((*stack_a)->next->index == max)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

void	if_three_args(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third && second < third)
		sa(stack_a, 1);
	if (first > second && first > third && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	if (first > second && first > third && second < third)
		ra(stack_a, 1);
	if (first < second && first < third && second > third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	if (first < second && first > third && second > third)
		rra(stack_a, 1);
}

void	if_four_args(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = stacklength(*stack_a) - 3;
	while (count > 0)
	{
		min_positioning(stack_a);
		pb(stack_a, stack_b, 1);
		count--;
	}
	if_three_args(stack_a);
	pa(stack_a, stack_b, 1);
}

void	if_five_args(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = stacklength(*stack_a) - 3;
	while (count > 0)
	{
		min_positioning(stack_a);
		pb(stack_a, stack_b, 1);
		count--;
	}
	if_four_args(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}
