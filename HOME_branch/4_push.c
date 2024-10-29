/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 20:21:09 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_pb(t_stack **dst, t_stack **src, int print, int aorb)
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
