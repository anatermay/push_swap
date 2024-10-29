

void	movement_executor(t_stack **a, t_stack **b, int pt[2], int side[2])
{
	int	both_r;
	int	position;
	int	p_side;
	int	target;
	int	t_side;

	position = pt[0];
	p_side = side[0];
	target = pt[1];
	t_side = side[1];
	printf("position: %d\n", position);
	printf("p_side: %d\n", p_side);
	printf("target: %d\n", target);
	printf("t_side: %d\n", t_side);
	both_r = be_positive(position - target);
	if (p_side == 0 && t_side == 0)
	{
		while (both_r-- > 0)
			rr(a, b, 1);
	}
	else if (p_side == 1 && t_side == 1)
	{
		while ((both_r--) > 0)
			rrr(a, b, 1);
	}
	/* 
	if (side == 0)
	{
		while (times > 0)
		{
			ra_rb(stack, 1, 0);
			times--;
		}
	}
	else if (side == 1)
	{
		while (times > 0)
		{
			rra_rrb(stack, 1, 0);
			times--;
		}
	} */
}

int	to_mid_calculator(t_stack **stack, int nbr)
{
	int		length;
	int		to_mid;

	length = stacklength(*stack) / 2;
	to_mid = length - nbr;
	to_mid = be_positive(to_mid);
	return (to_mid);
}

int	side_calculator(t_stack **stack, int nbr)
{
	int		length;
	int		to_mid;

	length = stacklength(*stack);
	if (nbr <= length / 2)
	{
		to_mid = 0;
	}
	else
		to_mid = 1;
	return (to_mid);
}

int	target_calculator(t_stack **stack_a, int value)
{
	t_stack	*temp;
	int		target;

	temp = *stack_a;
	target = 0;
	while (temp)
	{
		if (value > (*stack_a)->value
			&& value < (*stack_a)->next->value)
			return (target);
		target++;
		temp = temp->next;
	}
	return (-1);
}

int	position_calculator(t_stack *stack_b, int value)
{
	t_stack	*temp;
	int		position;


	temp = stack_b;
	position = 0;
	while (temp)
	{
		if (temp->value == value)
			return (position);
		position++;
		temp = temp->next;
	}
	return (-1);
}

int	cost_calculator(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		cost;
	int		position;
	int		target;
	int		value;

	cost = INT_MAX;
	temp = *stack_b;
	while (temp)
	{
		position = position_calculator(*stack_b, temp->value);
		target = target_calculator(stack_a, temp->value);
		temp->cost = position + target + 1;
		if (temp->cost < cost)
			cost = temp->cost;
		temp = temp->next;
	}
	temp = *stack_b;
	while (temp)
	{
		if (temp->cost == cost)
			value = temp->value;
		temp = temp->next;
	}
	return (value);
}

void	best_movements(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		min_cost_value;
	int		pt[2];
	int		side[2];

	temp = *stack_b;
	min_cost_value = cost_calculator(stack_a, stack_b);
	while (temp != NULL)
	{
		if (temp->value == min_cost_value)
		{
			pt[0] = position_calculator(*stack_b, temp->value);
			side[0] = side_calculator(stack_b, temp->value);
			pt[1] = target_calculator(stack_a, temp->value);
			side[1] = side_calculator(stack_a, temp->value);
			printf("pt[0]: %d\n", pt[0]);
			printf("side[0]: %d\n", side[0]);
			printf("pt[1]: %d\n", pt[1]);
			printf("side[1]: %d\n", side[1]);
			return ;
		}
		temp = temp->next;
	}
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (stacklength(*stack_a) > 3)
	{
		pa_pb(stack_b, stack_a, 1, 1);
	}
	if (!sorted(*stack_a))
		if_three_args(stack_a);
	while (stacklength(*stack_b) > 0)
	{
		while ((*stack_a))
		{
			printf("stack_a->value: %d\n", (*stack_a)->value);
			(*stack_a) = (*stack_a)->next;
		}
		best_movements(stack_a, stack_b);
		pa_pb(stack_a, stack_b, 1, 0);
	}
	if (!sorted(*stack_a))
		min_positioning(stack_a);
}


/* void	share_the_cake(t_stack **stack_a, t_stack **stack_b)
{
	int	mid;

	mid = (stacklength(*stack_a) / 2);
	while (stacklength(*stack_a) >= mid + 1)
	{
		if ((*stack_a)->index <= mid + 1)
			pa_pb(stack_b, stack_a, 1, 1);
		else
			ra_rb(stack_a, 1, 0);
	}
	while (stacklength(*stack_a) >= 1)
		pa_pb(stack_b, stack_a, 1, 1);
}

void	target_assignment(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		target;

	temp_b = *stack_b;
	while (temp_b)
	{
		target = 0;
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_b->index < temp_a->index)
			{
				if (target == 0 || temp_a->index < (*stack_a)->index)
					target = temp_a->position;
			}
			temp_a = temp_a->next;
		}
		temp_b->target = target;
		if (temp_b->target <= stacklength(*stack_a) / 2)
			temp_b->t_side = 0;
		else
			temp_b->t_side = 1;
		temp_b = temp_b->next;
	}
}

void	position_assignment(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		position;

	temp = *stack_a;
	position = 0;
	while (temp)
	{
		temp->position = position;
		position++;
		temp = temp->next;
	}
	temp = *stack_b;
	position = 0;
	while (temp)
	{
		temp->position = position;
		position++;
		temp = temp->next;
	}
}

void	index_assignment(t_stack **stack_a)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		index;

	temp1 = *stack_a;
	while (temp1)
	{
		index = 0;
		temp2 = *stack_a;
		while (temp2)
		{
			if (temp1->value > temp2->value)
				index++;
			temp2 = temp2->next;
		}
		temp1->index = index;
		temp1 = temp1->next;
	}
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	max;

	index_assignment(stack_a);
	position_assignment(stack_a, stack_b);
	target_assignment(stack_a, stack_b);
	share_the_cake(stack_a, stack_b);
	if (sorted(*stack_a) == 1)
		return ;
	max = max_value(stack_a);
	if ((*stack_a)->value == max)
		ra_rb(stack_a, 1, 0);
	else if ((*stack_a)->next->value == max)
		rra_rrb(stack_a, 1, 0);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa_sb(stack_a, 1, 0);
	while (*stack_b)
	{
		target_assignment(stack_a, stack_b);
		cost_calculator(stack_a, stack_b);
		sorting_movements(stack_a, stack_b);
	}
	if (sorted(*stack_a) == 0)
		min_positioning(stack_a);
}
 */

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	while (stacklength(*stack_a) > 3)
		pa_pb(stack_b, stack_a, 1, 1);
	if (sorted(*stack_a) == 0)
		if_three_args(stack_a);
	while (stacklength(*stack_b) > 0)
		best_movement_calculator(stack_a, stack_b);
	if (sorted(*stack_a) == 0)
		min_positioning(stack_a);
}