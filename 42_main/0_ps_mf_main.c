/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ps_mf_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:24:17 by aternero          #+#    #+#             */
/*   Updated: 2024/10/27 13:54:13 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	argc_checker(int argc, char **argv)
{
	if (argc <= 2)
	{
		if (argc == 2)
			valid_numbers(argv[1]);
		error(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	argc_checker(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	argv_extraction(argc, argv, &stack_a);
	checker(stack_a);
	push_swap(stack_a, stack_b);
	free_both_stack(&stack_a, &stack_b);
	return (0);
}
