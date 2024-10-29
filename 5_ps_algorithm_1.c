/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_algorithm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:27:02 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 20:08:39 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, 'a');
	pa_pb(stack_a, stack_b, 1, 0); // ¿False?
}

AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

static void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->side == 1 && cheapest->target->side == 1)
		rr(stack_a, stack_b, 1);
	else if (cheapest->side == 0
		&& cheapest->target->side == 0)
		rrr(stack_a, stack_b, 1);
	prep_for_push(stack_a, cheapest, 'a');
	prep_for_push(stack_b, cheapest->target, 'b');
	pa_pb(stack_b, stack_a, 1, 1); // ¿False?
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

static void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = ft_stacklength(stack_a);
	length_b = ft_stacklength(stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->position;
		if (stack_a->side == 0)
			stack_a->cost = length_a - stack_a->position;
		if (stack_a->target->side == 1)
				stack_a->cost = stack_a->cost + stack_a->target<_position;
		else
			stack_a->cost = stack_a->cost + (length_b - stack_a->target->position);
		stack_a = stack_a->next;
	}	
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*target;
	long	best;

	while (stack_a)
	{
		best = LONG_MIN;
		temp = stack_b;
		while (temp)
		{
			if (temp->value < stack_a->value
				&& temp->value > best)
			{
				best = temp->value;
				target = temp;
			}
			temp = temp->next;
		}
		if (best == LONG_MIN)
			stack_a->target = find_max(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}

void	current_index(t_stack *stack)
{
	int	index;
	int	median;

	index = 0;
	if (!stack)
			return ;
	median = ft_stacklength(stack_a) / 2;
	while (stack)
	{
		stack->position = index;
		if (index <= median)
				stack->side = 0;
		else
				stack->side = 1;
		stack = stack-next;
		index++;
	}
}

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	length_a;

	length_a = ft_stacklength(*stack_a);
	if (length_a-- > 3 && ft_sorted(*stack_a) == 0)
			pa_pb(stack_b, stack_a, 1, 1);
	if (length_a-- > 3 && ft_sorted(*stack_a) == 0)
			pa_pb(stack_b, stack_a, 1, 1);
	while (length_a-- > 3 && ft_sorted(*stack_a) == 0)
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	if_three_args(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	ft_positioning(stack_a);
}

void	ft_sort_inversed(t_stack **stack_a, t_stack **stack_b)
{
	int		length;
	
	length = ft_stacklength(*stack_a);
	while (length > 0)
	{
		ft_pa_pb(stack_b, stack_a, 1, 1);
		length--;
	}
	length = ft_stacklength(*stack_b);
	while (length > 0)
	{
		ft_rra_rrb(stack_b, 1, 1);
		ft_pa_pb(stack_a, stack_b, 1, 0);
		length--;
	}
}

void	ps_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (if_inversely_sorted(stack_a))
		ft_sort_inversed(stack_a, stack_b);
	else if (if_partially_sorted(stack_a))
		ft_positioning(stack_a);
	else if (if_partially_and_inversely_sorted(stack_a))
	{
		ft_sort_inversed(stack_a, stack_b);
		ft_positioning(stack_a);
	}
	else
		cost_algorithm(stack_a, stack_b);
}
