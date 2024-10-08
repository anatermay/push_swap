/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complementary_bso.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:15:07 by aternero          #+#    #+#             */
/*   Updated: 2024/10/07 14:14:01 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int AORB -> a = 0 && b = 1

void	ft_aorb_rot(t_stack **stack, int cost, int aorb)
{
	while (cost != 0)
	{
		if (cost > 0)
		{
			ft_ra_rb(stack, 1, aorb);
			cost--;
		}
		if (cost < 0)
		{
			ft_rra_rrb(stack, 1, aorb);
			cost++;
		}
	}
}

void	ft_rr_rot(t_stack **a, t_stack **b, int acost, int bcost)
{
	while (acost > 0 && bcost > 0)
	{
		ft_rr(a, b, 1);
		acost--;
		bcost--;
	}
}
