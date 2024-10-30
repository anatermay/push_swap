/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:27:21 by aternero          #+#    #+#             */
/*   Updated: 2024/10/30 12:06:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_prev_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (if_inversely_sorted(stack_a))
		sort_inversed(stack_a, stack_b);
	else if (if_partially_sorted(stack_a))
		min_positioning(stack_a);
	else if (if_partially_and_inversely_sorted(stack_a))
	{
		sort_inversed(stack_a, stack_b);
		min_positioning(stack_a);
	}
	if (stacklength(*stack_a) > 5 && (!if_partially_sorted(stack_a)
			|| !if_partially_and_inversely_sorted(stack_a)
			|| !if_inversely_sorted(stack_a)))
		algorithm(stack_a, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	length;

	stack_b = NULL;
	length = stacklength(stack_a);
	if (length == 2 && sorted(stack_a) == 0)
		sa_sb(&stack_a, 1, 0);
	else if (length == 3 && sorted(stack_a) == 0)
		if_three_args(&stack_a);
	else if (length == 4 && sorted(stack_a) == 0)
		if_four_args(&stack_a, &stack_b);
	else if (length == 5 && sorted(stack_a) == 0)
		if_five_args(&stack_a, &stack_b);
	else if (length > 5 && sorted(stack_a) == 0)
		ps_prev_algorithm(&stack_a, &stack_b);
}

void	argv_extraction(int argc, char **argv, t_stack **stack_a)
{
	int		index[2];
	t_stack	*temp;

	index[0] = argc - 1;
	index[1] = 0;
	while (index[0] > 0)
	{
		valid_numbers(argv[index[0]]);
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			error(0);
		temp->value = atoi(argv[index[0]]);
		temp->position = index[1];
		temp->next = *stack_a;
		*stack_a = temp;
		index[0]--;
		index[1]++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 2)
	{
		if (argc == 2)
			valid_numbers(argv[1]);
		error(0);
	}
	stack_a = NULL;
	stack_b = NULL;
	argv_extraction(argc, argv, &stack_a);
	checker(stack_a);
	push_swap(stack_a, stack_b);
	free_both_stack(&stack_a, &stack_b);
	return (0);
}
