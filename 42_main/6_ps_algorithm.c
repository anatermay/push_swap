/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_ps_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:49:48 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 10:50:42 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	min_cost_target(t_stack **stack)
{
	t_stack	*temp;
	int		min_cost;
	int		target;
	int		min_target;

	temp = *stack;
	min_cost = temp->cost;
	target = temp->target;
	min_target = 0;
	while (temp != NULL)
	{
		if (temp->cost < min_cost)
		{
			min_cost = temp->cost;
			min_target = target;
		}
		temp = temp->next;
	}
	return (min_target);
}

int	min_cost_position(t_stack **stack)
{
	t_stack *temp;
	int		min_cost;
	int		position;
	int		min_position;

	temp = *stack;
	min_cost = temp->cost;
	position = 0;
	min_position = 0;
	while (temp != NULL)
	{
		if (temp->cost < min_cost)
		{
			min_cost = temp->cost;
			min_position = position;
		}
		temp = temp->next;
		position++;
	}
	return (min_position);
}

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

void	continue_positioning(t_stack **a, t_stack **b, int ps, int ts, int aorb)
{
	if (ps == 0 && ts == 0)
	{
		if (aorb == 0)
			ra_rb(a, 1, 0);
		else
			ra_rb(b, 1, 1);
	}
	if (ps == 0 && ts == 1)
	{
		if (aorb == 0)
			ra_rb(a, 1, 0);
		else
			rra_rrb(b, 1, 0);
	}
	if (ps == 1 && ts == 0)
	{
		if (aorb == 0)
			rra_rrb(a, 1, 0);
		else
			ra_rb(b, 1, 1);
	}
	if (ps == 1 && ts == 1)
	{
		if (aorb == 0)
			rra_rrb(a, 1, 0);
		else
			rra_rrb(b, 1, 0);
	}
}

void	min_cost_positioning(t_stack **stack_a, t_stack **stack_b, t_stack *min)
{
	int	position;
	int	target;
	int	length[2];

	while (min->position > 0 && min->target > 0)
	{
		if (min->p_side == 0 && min->t_side == 0)
			rr(stack_a, stack_b, 1);
		else if (min->p_side == 0 && min->t_side == 1)
		{
			rra_rrb(stack_a, 1, 0);
			ra_rb(stack_b, 1, 1);
		}
		else if (min->p_side == 1 && min->t_side == 0)
		{
			ra_rb(stack_a, 1, 0);
			rra_rrb(stack_b, 1, 0);
		}
		else if (min->p_side == 1 && min->t_side == 1)
			rrr(stack_a, stack_b, 1);
		min->position--;
		min->target--;
	}
	while (min->position > 0)
	{
		continue_positioning(stack_a, stack_b, min->p_side, min->t_side, 1);
		min->position--;
	}
	while (min->target > 0)
	{
		continue_positioning(stack_a, stack_b, min->p_side, min->t_side, 0);
		min->target--;
	}
}

int	target_position(t_stack **stack_a, int value);

int	position_calculator(t_stack **stack_b, int value);

t_stack	*cost_calculator(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*min_cost;
	int		length[2];

	temp = *stack_b;
	min_cost->cost = INT_MAX;
	length[0] = stacklength(*stack_a);
	length[1] = stacklength(*stack_b);
	while (temp)
	{
		temp->position = position_calculator(*stack_b, temp->value);
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
		if (temp->cost < min_cost->cost)
			min_cost = temp;
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
	printf("Operation number 1\n");
	print_stacks(*stack_a, *stack_b);
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_cost;

	if (!stack_a || !stack_b || !*stack_a)
		return ;
	printf("Operation number 0\n");
	print_stacks(*stack_a, *stack_b);
	transaction_to_b(stack_a, stack_b);
	while (stacklength(*stack_b) > 0)
	{
		min_cost = cost_calculator(stack_a, stack_b);
		min_cost_positioning(stack_a, stack_b, min);
	}
	if (!sorted(*stack_a))
		min_positioning(stack_a);
}
 */