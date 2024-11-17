/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algorithm_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:30:34 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 19:21:33 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	be_positive(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	sorting_executor(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_rotate(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate(a, b, &cost_a, &cost_b);
	rotate_stack_a(a, &cost_a);
	rotate_stack_b(b, &cost_b);
	pa(a, b, 1);
}

void	low_cost_sorting_strategy(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cost_a;
	int		cost_b;
	int		cheap;
	int		current_cost;

	temp = *stack_b;
	cheap = INT_MAX;
	while (temp)
	{
		current_cost = abs(temp->cost_a) + abs(temp->cost_b);
		if (current_cost < cheap)
		{
			cheap = current_cost;
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	sorting_executor(stack_a, stack_b, cost_a, cost_b);
}

void	cost_calculator(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		length_a;
	int		length_b;

	temp = *stack_b;
	length_a = stacklength(*stack_a);
	length_b = stacklength(*stack_b);
	while (temp)
	{
		temp->cost_b = temp->position;
		if (temp->position > length_b / 2)
			temp->cost_b = (length_b - temp->position) * -1;
		temp->cost_a = temp->target;
		if (temp->target > length_a / 2)
			temp->cost_a = (length_a - temp->target) * -1;
		temp = temp->next;
	}
}

void	bubble_sort(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		aux;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (temp && temp->next)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value > temp2->value)
			{
				aux = temp->value;
				temp->value = temp2->value;
				temp2->value = aux;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
