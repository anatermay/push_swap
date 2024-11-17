/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:05:00 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 21:04:51 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

void	free_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	free_stack(stack_a);
	free_stack(stack_b);
}
