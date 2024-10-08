/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_bso_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:04 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 14:19:30 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int AORB -> a = 0 && b = 1

void	ft_rr(t_stack **a, t_stack **b, int print)
{
	ft_ra_rb(a, 0, 0);
	ft_ra_rb(b, 0, 1);
	if (print)
		write(1, "rr\n", 3);
}

void	ft_ra_rb(t_stack **stack, int print, int aorb)
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
				write(1, "ra\n", 3);
			else
				write(1, "rb\n", 3);
		}
	}
}

