/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:02:12 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 20:25:45 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	reading_comprehension(char *bso, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(bso, "pa", 2) == 0)
		pa(&stack_a, &stack_b, 0);
	else if (ft_strncmp(bso, "pb", 2) == 0)
		pb(&stack_a, &stack_b, 0);
	else if (ft_strncmp(bso, "rr", 2) == 0)
		rr(&stack_a, &stack_b, 0);
	else if (ft_strncmp(bso, "rra", 3) == 0)
		rra(&stack_a, 0);
	else if (ft_strncmp(bso, "rrb", 3) == 0)
		rrb(&stack_b, 0);
	else if (ft_strncmp(bso, "rrr", 3) == 0)
		rrr(&stack_a, &stack_b, 0);
	else if (ft_strncmp(bso, "ra", 2) == 0)
		ra(&stack_a, 0);
	else if (ft_strncmp(bso, "rb", 2) == 0)
		rb(&stack_b, 0);
	else if (ft_strncmp(bso, "sa", 2) == 0)
		sa(&stack_a, 0);
	else if (ft_strncmp(bso, "sb", 2) == 0)
		sb(&stack_b, 0);
	else if (ft_strncmp(bso, "ss", 2) == 0)
		ss(&stack_a, &stack_b, 0);
	else
		return (0);
}

void	input_reader(int argc, char **argv, t_stack *stack_a)
{
	int	index;

	index = argc - 1;
	while (index > 0)
	{
		valid_numbers(argv[index]);
		stackadd(stack_a, stacknew(ft_atoi(argv[index])));
		index--;
	}
	stack_args_checker(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*bso_reader;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	input_reader(argc, argv, stack_a);
	while (1)
	{
		bso_reader = get_next_line(STDIN_FILENO);
		if (!bso_reader)
			break ;
		if (reading_comprehension(bso_reader, stack_a, stack_b) == 0)
			free_both_stack(stack_a, stack_b);
		free_str(bso_reader);
	}
	if (sorted(stack_a) == 1 && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_both_stack(stack_a, stack_b);
}
