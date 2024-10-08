/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_bso_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:04 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 14:29:19 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int AORB -> a = 0 && b = 1

void	ft_rrr(t_stack **a, t_stack **b, int print)
{
	ft_rra_rrb(a, 0, 0);
	ft_rra_rrb(b, 0, 1);
	if (print)
		write(1, "rrr\n", 4);
}

void	ft_rra_rrb(t_stack **stack, int print, int aorb)
{
	t_stack	*first;
	t_stack	*last;

	while (!(*stack) || (*stack)->next == NULL)
		return ;
	first = *stack;
	while ((*stack)->next)
	{
		if (!(*stack)->next->next)
			last = (*stack)->next;
		*stack = (*stack)->next;
	}
	first->prev = last;
	last->next = first;
	*stack = (*stack)->next;
	first->next = NULL;
	(*stack)->prev = NULL;
	if (ft_sorted(*stack) == 1)
	{
		if (print)
		{
			if (aorb == 0)
				write(1, "rra\n", 4);
			else
				write(1, "rrb\n", 4);
		}
	}
}
