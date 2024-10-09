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

int	if_partially_sorted(t_stack **stack_a)
{
	t_stack	*temp;
	int		sorted;

	temp = *stack_a;
	sorted = 1;
	while (temp && temp->next != NULL)
	{
		if ((temp->value < temp->next->value)
			&& (temp->value == ft_min_value(stack_a))
			&& (temp->next->value == ft_max_value(stack_a)))
			sorted = 0;
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
			&& (temp->value == ft_max_value(stack_a))
			&& (temp->next->value == ft_min_value(stack_a)))
			return (0);
		temp = temp->next;
	}
	return (1);
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
