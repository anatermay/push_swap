/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ps_mf_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:24:17 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 18:50:16 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argv_extraction(int argc, char **argv, t_stack **stack_a)
{
	int		index[2];
	t_stack	*temp;

	index[0] = argc - 1;
	index[1] = 0;
	while (index[0] > 0)
	{
		ft_valid_numbers(argv[index[0]]);
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			ft_error(0);
		temp->value = ft_atoi(argv[index[0]]);
		temp->position = index[1];
		temp->next = *stack_a;
		*stack_a = temp;
		index[0]--;
		index[1]++;
	}
}

void	ft_argc_checker(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		ft_error(0);
	else if (argc == 2)
	{
		ft_valid_numbers(argv);
		argv == split(argv[1], ' ');
	}
	
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_argc_checker(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_argv_extraction(argc, argv, &stack_a);
	ft_checker(stack_a);
	ft_push_swap(stack_a, stack_b);
	ft_free_both_stack(&stack_a, &stack_b);
	return (0);
}
