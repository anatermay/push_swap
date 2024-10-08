/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_bso_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:04 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 12:12:15 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// INT AORB -> a = 0 && b = 1

void	ft_ss(t_stack **a, t_stack **b, int print)
{
	ft_sa_sb(a, 0, 0);
	ft_sa_sb(b, 0, 1);
	if (print)
		write(1, "ss\n", 3);
}

void	ft_sa_sb(t_stack **stack, int print, int aorb)
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
