/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_bso_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:04 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 18:07:42 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b, int print)
{
	ra_rb(a, 0, 0);
	ra_rb(b, 0, 1);
	if (print)
		write(1, "rr\n", 3);
}

void	ra_rb(t_stack **stack, int print, int aorb)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	last = stacklast(stack);
	first->next = NULL;
	last->next = first;
	if (print)
	{
		if (aorb == 0)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}
