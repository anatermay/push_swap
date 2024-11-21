/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:48:27 by aternero          #+#    #+#             */
/*   Updated: 2024/11/20 12:25:55 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacklast(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

int	stacklength(t_stack *stack)
{
	int	length;

	length = 0;
	while (stack)
	{
		length++;
		stack = stack->next;
	}
	return (length);
}

void	stackadd(t_stack **stack, t_stack *new, bool back)
{
	t_stack	*temp;

	if (!back)
	{
		new->next = *stack;
		*stack = new;
	}
	else
	{
		if (!*stack || !new)
			return ;
		if (!*stack)
		{
			new->next = NULL;
			*stack = new;
			return ;
		}
		else
		{
			temp = stacklast(stack);
			temp->next = new;
		}
	}
}

t_stack	*stacknew(int value)
{
	t_stack	*newnode;

	newnode = 0;
	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
	{
		free(newnode);
		return (NULL);
	}
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

t_stack	*stackdup(t_stack *original)
{
	t_stack	*dup;
	t_stack	*temp;

	dup = NULL;
	while (original)
	{
		temp = stacknew(original->value);
		stackadd(&dup, temp, 0);
		original = original->next;
	}
	return (dup);
}
