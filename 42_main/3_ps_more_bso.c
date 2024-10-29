/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_more_bso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:15:07 by aternero          #+#    #+#             */
/*   Updated: 2024/10/27 19:19:42 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aorb_rot(t_stack **stack, int cost, int aorb)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			ra_rb(stack, 1, aorb);
			cost--;
		}
		if (cost < 0)
		{
			rra_rrb(stack, 1, aorb);
			cost++;
		}
	}
}

void	rr_rot(t_stack **a, t_stack **b, int acost, int bcost)
{
	while (acost > 0 && bcost > 0)
	{
		rr(a, b, 1);
		acost--;
		bcost--;
	}
}

void	rrr_rot(t_stack **a, t_stack **b, int acost, int bcost)
{
	while (acost < 0 && bcost < 0)
	{
		rrr(a, b, 1);
		acost++;
		bcost++;
	}
}