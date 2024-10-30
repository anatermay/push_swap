/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4b_ps_if_partially_sorted.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:34:53 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 16:15:25 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_inversed(t_stack **stack_a, t_stack **stack_b)
{
	int		length;

	length = stacklength(*stack_a);
	while (length > 0)
	{
		pa_pb(stack_b, stack_a, 1, 1);
		length--;
	}
	length = stacklength(*stack_b);
	while (length > 0)
	{
		rra_rrb(stack_b, 1, 1);
		pa_pb(stack_a, stack_b, 1, 0);
		length--;
	}
}

int	if_partially_sorted(t_stack **stack_a)
{
	t_stack	*temp;
	int		sorted;

	temp = *stack_a;
	sorted = 0;
	while (temp && temp->next != NULL)
	{
		if ((temp->value < temp->next->value)
			&& (temp->value == min_value(stack_a))
			&& (temp->next->value == max_value(stack_a)))
			sorted = 1;
		temp = temp->next;
	}
	return (sorted);
}

int	if_partially_and_inversely_sorted(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if ((temp->value < temp->next->value)
			&& (temp->value == max_value(stack_a))
			&& (temp->next->value == min_value(stack_a)))
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	if_inversely_sorted(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
