/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_stack_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:53:13 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 11:12:52 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, int sum_up)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (sum_up == 0 || sum_up == 1)
			printf("Value:\n\t%d\n", temp->value);
		if (sum_up == 0)
		{
			printf("Cost:\n\t%d\n", temp->cost);
			printf("Position:\n\t%d\n", temp->position);
			printf("P_side:\n\t%d\n", temp->p_side);
			printf("Target:\n\t%d\n", temp->target);
			printf("T_side:\n\t%d\n", temp->t_side);
		}
		temp = temp->next;
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b, int sum_up)
{
	printf("Stack A:\n");
	print_stack(stack_a, sum_up);
	printf("Stack B:\n");
	print_stack(stack_b, sum_up);
}
