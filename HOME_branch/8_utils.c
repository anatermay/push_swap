/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:39:56 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 21:07:31 by aternero         ###   ########.fr       */
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

int	be_positive(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	str_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
