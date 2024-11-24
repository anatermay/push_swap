/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:27 by aternero          #+#    #+#             */
/*   Updated: 2024/11/22 14:17:38 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int		max;

	max = (stacklength(*stack_a) / 2);
	while (stacklength(*stack_a) >= max + 1)
	{
		if ((*stack_a)->index <= max + 1)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
	}
	while ((stacklength(*stack_a) >= 1))
		pb(stack_a, stack_b, 1);
	stack_a_sorting(stack_a);
	while (*stack_b)
	{
		target_assignment(stack_a, stack_b);
		cost_calculator(stack_a, stack_b);
		low_cost_sorting_strategy(stack_a, stack_b);
	}
	if (!sorted(*stack_a))
		min_positioning(stack_a);
}

void	push_swap(t_stack *stack_a)
{
	t_stack	*stack_b;
	int		length;

	if (!stack_a)
		return ;
	stack_b = NULL;
	length = stacklength(stack_a);
	index_assignment(&stack_a);
	position_assignment(&stack_a);
	position_assignment(&stack_b);
	target_assignment(&stack_a, &stack_b);
	if (length == 2 && sorted(stack_a) == 0)
		sa(&stack_a, 1);
	else if (length == 3 && sorted(stack_a) == 0)
		if_three_args(&stack_a);
	else if (length == 4 && sorted(stack_a) == 0)
		if_four_args(&stack_a, &stack_b);
	else if (length == 5 && sorted(stack_a) == 0)
		if_five_args(&stack_a, &stack_b);
	else if (length > 5 && sorted(stack_a) == 0)
		algorithm(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int		index;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	temp = NULL;
	index = argc - 1;
	while (index > 0)
	{
		valid_numbers(argv[index]);
		temp = stacknew(ft_atoi(argv[index]));
		stackadd(&stack_a, temp, 0);
		index--;
	}
	duplicated(stack_a);
	if (sorted(stack_a) == 1)
	{
		free_stack(&stack_a);
		ft_error(0);
	}
	push_swap(stack_a);
	return (0);
}
