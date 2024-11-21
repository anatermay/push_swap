/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:02:12 by aternero          #+#    #+#             */
/*   Updated: 2024/11/21 12:43:33 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

bool	reader(char *bso, t_stack **stack_a, t_stack **stack_b)
{
	if (!strncmp(bso, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!strncmp(bso, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!strncmp(bso, "rra\n", 4))
		rra(stack_a, 0);
	else if (!strncmp(bso, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!strncmp(bso, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else if (!strncmp(bso, "ra\n", 3))
		ra(stack_a, 0);
	else if (!strncmp(bso, "rb\n", 3))
		rb(stack_b, 0);
	else if (!strncmp(bso, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!strncmp(bso, "sa\n", 3))
		sa(stack_a, 0);
	else if (!strncmp(bso, "sb\n", 3))
		sb(stack_b, 0);
	else if (!strncmp(bso, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else
		write(1, "Error\n", 6);
	return (1);
}

void	input_checker(int argc, char **argv, t_stack **stack_a)
{
	t_stack	*temp;
	int		index;

	index = argc - 1;
	while (index > 0)
	{
		valid_numbers(argv[index]);
		temp = stacknew(ft_atoi(argv[index]));
		temp->next = *stack_a;
		*stack_a = temp;
		index--;
	}
	stack_args_checker(*stack_a);
}

int	main(int ac, char **agv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*bso_reader;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	input_checker(ac, agv, &stack_a);
	while (1)
	{
		bso_reader = get_next_line(STDIN_FILENO);
		if (!bso_reader)
			break ;
		if (reader(bso_reader, &stack_a, &stack_b) == 0)
			free_both_stack(&stack_a, &stack_b);
		free(bso_reader);
	}
	if (stack_a && stack_b == NULL && sorted(stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_both_stack(&stack_a, &stack_b);
	return (0);
}
