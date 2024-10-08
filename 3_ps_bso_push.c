/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ps_bso_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:51:04 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 18:50:44 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int AORB -> a = 0 && b = 1
IF PA -> dst = t_stack **a && src = t_stack **b;
IF PB -> dst = t_stack **b && src = t_stack **a; */

void	ft_pa_pb(t_stack **dst, t_stack **src, int print, int aorb)
{
	t_stack	*temp;

	if (!(*src))
		return ;
	temp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = temp;
	if (print)
	{
		if (!aorb)
			write(1, "pa\n", 3);
		if (aorb)
			write(1, "pb\n", 3);
	}
}
