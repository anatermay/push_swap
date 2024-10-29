/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 20:21:09 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, int print)
{
	sa_sb(a, 0, 0);
	sa_sb(b, 0, 1);
	if (print)
		write(1, "ss\n", 3);
}

void	sa_sb(t_stack **stack, int print, int aorb)
{
	t_stack	*temp;

	while (!(*stack) || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (print)
	{
		if (!aorb)
			write(1, "sa\n", 3);
		if (aorb)
			write(1, "sb\n", 3);
	}
}
