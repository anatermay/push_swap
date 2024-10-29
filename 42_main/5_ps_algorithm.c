/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:06:48 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 11:13:05 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	side_calculator(t_stack **stack, int nbr)
{
	int		length;
	int		to_mid;

	length = stacklength(*stack) / 2;
	if (nbr < length)
		to_mid = 0;
	else
		to_mid = 1;
	return (to_mid);
}

void	continue_positioning_stack_b(t_stack **b, int ps, int ts)
{
	if (ps == 0 && ts == 0)
		ra_rb(b, 1, 1);
	if (ps == 0 && ts == 1)
		rra_rrb(b, 1, 0);
	if (ps == 1 && ts == 0)
		ra_rb(b, 1, 1);
	if (ps == 1 && ts == 1)
		rra_rrb(b, 1, 0);
}

void	continue_positioning_stack_a(t_stack **a, int ps, int ts)
{
	if (ps == 0 && ts == 0)
		ra_rb(a, 1, 0);
	if (ps == 0 && ts == 1)
		ra_rb(a, 1, 0);
	if (ps == 1 && ts == 0)
		rra_rrb(a, 1, 0);
	if (ps == 1 && ts == 1)
		rra_rrb(a, 1, 0);
}

void	continue_positioning_both(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->p_side == 0 && (*stack_b)->t_side == 0)
		rr(stack_a, stack_b, 1);
	else if ((*stack_b)->p_side == 0 && (*stack_b)->t_side == 1)
	{
		rra_rrb(stack_a, 1, 0);
		ra_rb(stack_b, 1, 1);
	}
	else if ((*stack_b)->p_side == 1 && (*stack_b)->t_side == 0)
	{
		ra_rb(stack_a, 1, 0);
		rra_rrb(stack_b, 1, 0);
	}
	else if ((*stack_b)->p_side == 1 && (*stack_b)->t_side == 1)
		rrr(stack_a, stack_b, 1);
	(*stack_b)->position--;
	(*stack_b)->target--;
}

void	min_cost_positioning(t_stack **stack_a, t_stack **stack_b)
{
	int	p_side;
	int	t_side;

	while (*stack_b)
	{
		if ((*stack_b)->cost == cost_calculator(stack_a, stack_b))
		{
			p_side = (*stack_b)->p_side;
			t_side = (*stack_b)->t_side;
			while ((*stack_b)->position > 0 && (*stack_b)->target > 0)
				continue_positioning_both(stack_a, stack_b);
			while ((*stack_b)->position-- > 0)
				continue_positioning_stack_b(stack_b, p_side, t_side);
			while ((*stack_b)->target-- > 0)
				continue_positioning_stack_a(stack_a, p_side, t_side);
			break ;
		}
		(*stack_b) = (*stack_b)->next;
	}
}

int	target_calculator(t_stack **stack_a, int value)
{
	t_stack	*temp;
	int		target;

	temp = *stack_a;
	target = 0;
	while (temp)
	{
		if (temp->next && temp->value < value && temp->next->value > value)
			return (target + 1);
		target++;
		temp = temp->next;
	}
	return (-1);
}

int	position_calculator(t_stack **stack_b, int value)
{
	t_stack	*temp;
	int		position;

	temp = *stack_b;
	position = 0;
	while (temp)
	{
		if (temp->value == value)
			return (position);
		position++;
		temp = temp->next;
	}
	return (-1);
}

int	cost_calculator(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		min_cost;
	int		length[2];

	temp = *stack_b;
	min_cost = INT_MAX;
	length[0] = stacklength(*stack_a);
	length[1] = stacklength(*stack_b);
	while (temp)
	{
		temp->position = position_calculator(stack_b, temp->value);
		temp->p_side = side_calculator(stack_b, temp->position);
		temp->target = target_calculator(stack_a, temp->value);
		temp->t_side = side_calculator(stack_a, temp->target);
		if (temp->p_side == 0 && temp->t_side == 0)
			temp->cost = temp->position + temp->target;
		else if (temp->p_side == 0 && temp->t_side == 1)
			temp->cost = temp->position + length[0] - temp->target;
		else if (temp->p_side == 1 && temp->t_side == 0)
			temp->cost = length[1] - temp->position + temp->target;
		else if (temp->p_side == 1 && temp->t_side == 1)
			temp->cost = length[1] - temp->position + length[0] - temp->target;
		if (temp->cost < min_cost)
			min_cost = temp->cost;
		temp = temp->next;
	}
	return (min_cost);
}


void	transaction_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		length;

	length = stacklength(*stack_a);
	while (length > 3)
	{
		pa_pb(stack_b, stack_a, 1, 1);
		length--;
	}
	if_three_args(stack_a);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a)
		return ;
	transaction_to_b(stack_a, stack_b);
	while (stacklength(*stack_b) > 0)
	{
		min_cost_positioning(stack_a, stack_b);
		pa_pb(stack_a, stack_b, 1, 0);
	}
	if (!sorted(*stack_a))
		min_positioning(stack_a);
	print_stacks(*stack_a, *stack_b, 1);
}
