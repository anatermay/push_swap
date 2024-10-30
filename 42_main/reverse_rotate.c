/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_bso_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:04 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 18:07:44 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b, int print)
{
	rra_rrb(a, 0, 0);
	rra_rrb(b, 0, 1);
	if (print)
		write(1, "rrr\n", 4);
}

void	rra_rrb(t_stack **stack, int print, int aorb)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	last = stacklast(stack);
	first = *stack;
	while (first->next->next != NULL)
		first = first->next;
	first->next = NULL;
	last->next = *stack;
	*stack = last;
	if (print)
	{
		if (aorb == 0)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}
