/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:27 by aternero          #+#    #+#             */
/*   Updated: 2024/11/12 13:37:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		write(1, "rr\n", 3);
}

void	ra(t_stack **stack_a, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = stacklast(stack_a);
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_a, bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = stacklast(stack_a);
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "rb\n", 3);
}
