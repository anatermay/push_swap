/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ps_more_ina.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:37:56 by aternero          #+#    #+#             */
/*   Updated: 2024/10/08 13:54:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_min_value(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*min;

	temp = *stack_a;
	min = temp;
	while (temp != NULL)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_stack	*ft_max_value(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*max;

	temp = *stack_a;
	max = temp;
	while (temp != NULL)
	{
		if (temp->value > max->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}