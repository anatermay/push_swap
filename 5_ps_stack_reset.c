/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_ps_stack_reset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:46:34 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 17:25:01 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target_position(t_stack *stack, t_stack **stack_cmp)
{
	int		position;
	t_stack	*temp;
	position = 0;
	temp = *stack_cmp;
	while (temp)
		{
		if (stack->value < temp->value)
			break ;
		position++;
		temp = temp->next;
	}
	return (position);
}

int	find_position(t_stack *stack, t_stack **stack_cmp)
{
	int		position;
	t_stack	*temp;
		position = 0;
	temp = *stack_cmp;
	while (temp)
	{
		if (stack->value == temp->value)
			break ;
		position++;
		temp = temp->next;
	}
	return (position);
}

void	stack_b_reset(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		(*stack_b)->position = find_position(*stack_b, stack_a);
		if ((*stack_b)->position <= stacklength(*stack_b) / 2)
			(*stack_b)->p_side = 0;
		else
			(*stack_b)->p_side = 1;
		(*stack_b)->target = find_target_position(*stack_b, stack_a);
		if ((*stack_b)->target <= stacklength(*stack_a) / 2)
			(*stack_b)->t_side = 0;
		else
			(*stack_b)->t_side = 1;
		(*stack_b)->aorb = 1;
		(*stack_b)->length_a = stacklength(*stack_a);
		(*stack_b)->length_b = stacklength(*stack_b);
		(*stack_b)->cmd = NULL;
		(*stack_b) = (*stack_b)->next;
	}
}

void	stack_a_reset(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		(*stack_a)->position = find_position(*stack_a, stack_b);
		if ((*stack_a)->position <= stacklength(*stack_a) / 2)
			(*stack_a)->p_side = 0;
		else
			(*stack_a)->p_side = 1;
		(*stack_a)->target = find_target_position(*stack_a, stack_b);
		if ((*stack_a)->target <= stacklength(*stack_b) / 2)
			(*stack_a)->t_side = 0;
		else
			(*stack_a)->t_side = 1;
		(*stack_a)->aorb = 0;
		(*stack_a)->length_a = stacklength(*stack_a);
		(*stack_a)->length_b = stacklength(*stack_b);
		(*stack_a)->cmd = NULL;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = NULL;
}

void	stack_reset(t_stack **stack_a, t_stack **stack_b)
{
	stack_a_reset(stack_a, stack_b);
	stack_b_reset(stack_a, stack_b);
}
