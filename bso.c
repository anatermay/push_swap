/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:09:00 by aternero          #+#    #+#             */
/*   Updated: 2024/11/20 14:25:27 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_b(t_stack **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			rb(stack_b, 1);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			rrb(stack_b, 1);
		}
	}
}

void	rotate_stack_a(t_stack **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			(*cost)--;
			ra(stack_a, 1);
		}
		else if (*cost < 0)
		{
			(*cost)++;
			rra(stack_a, 1);
		}
	}
}

void	rotate(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b, 1);
	}
}

void	reverse_rotate(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca < 0 && *cb < 0)
	{
		(*ca)++;
		(*cb)++;
		rrr(a, b, 1);
	}
}
