/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:27 by aternero          #+#    #+#             */
/*   Updated: 2024/11/12 13:37:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}

void	rra(t_stack **stack_a, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack_a) || (*stack_a)->next == NULL)
		return ;
	last = stacklast(stack_a);
	first = *stack_a;
	while (first->next->next != NULL)
		first = first->next;
	first->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack_b) || (*stack_b)->next == NULL)
		return ;
	last = stacklast(stack_b);
	first = *stack_b;
	while (first->next->next != NULL)
		first = first->next;
	first->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (print)
		write(1, "rrb\n", 4);
}
