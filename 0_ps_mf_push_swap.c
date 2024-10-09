/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ps_mf_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:27:21 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 16:29:05 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	length;

	stack_b = NULL;
	length = ft_stacklength(stack_a);
	if (length == 2 && ft_sorted(stack_a) == 0)
		ft_sa_sb(&stack_a, 1, 0);
	else if (length == 3 && ft_sorted(stack_a) == 0)
		if_three_args(&stack_a);
	else if (length == 4 && ft_sorted(stack_a) == 0)
		if_four_args(&stack_a, &stack_b);
	else if (length == 5 && ft_sorted(stack_a) == 0)
		if_five_args(&stack_a, &stack_b);
	else if (length > 5 && ft_sorted(stack_a) == 0)
		ps_algorithm(&stack_a, &stack_b);
}
