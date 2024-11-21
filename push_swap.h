/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:39:55 by aternero          #+#    #+#             */
/*   Updated: 2024/11/21 12:38:41 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stddef.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target;
	int				cost_a;
	int				cost_b;
	int				cost;
	struct s_stack	*next;
}					t_stack;

/*ARGV_CHECKER*/
bool	sorted(t_stack *stack_a);
bool	duplicates(t_stack *stack_a);
void	stack_args_checker(t_stack *stack);
void	valid_numbers(char *str);
void	error(bool print);

/*BSO*/
void	rotate_stack_b(t_stack **stack_b, int *cost);
void	rotate_stack_a(t_stack **stack_a, int *cost);
void	rotate(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	reverse_rotate(t_stack **a, t_stack **b, int *ca, int *cb);

/*COST ALGORITHM*/
void	bubble_sort(t_stack **stack);
void	cost_calculator(t_stack **stack_a, t_stack **stack_b);
void	low_cost_sorting_strategy(t_stack **stack_a, t_stack **stack_b);
void	sorting_executor(t_stack **a, t_stack **b, int cost_a, int cost_b);
int		be_positive(int nbr);
void	index_assignment(t_stack **stack);
int		index_calculator(t_stack *stack, int value);
void	position_assignment(t_stack **stack);
void	target_assignment(t_stack **a, t_stack **b);
int		target_calculator(t_stack **a, int index, int target, int position);

/*IF NBR ARGS*/
void	stack_a_sorting(t_stack **stack_a);
void	bubble_sort(t_stack **stack);
void	if_three_args(t_stack **stack_a);
void	if_four_args(t_stack **stack_a, t_stack **stack_b);
void	if_five_args(t_stack **stack_a, t_stack **stack_b);

/*MEMORY HANDLING*/
void	free_stack(t_stack **stack);
void	free_both_stack(t_stack **stack_a, t_stack **stack_b);

/*MIN HANDLING*/
void	min_positioning(t_stack **stack);
int		min_position(t_stack **stack);
int		max_index(t_stack *stack);

/*PUSH SWAP*/
void	algorithm(t_stack **stack_a, t_stack **stack_b);
void	push_swap(t_stack *stack_a, t_stack *stack_b);
t_stack	*stackcreation(int argc, char **argv, t_stack *stack_a);
int		main(int argc, char **argv);

/*PUSH*/
void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_a, t_stack **stack_b, bool print);

/*REVERSE ROTATE*/
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void	rra(t_stack **stack_a, bool print);
void	rrb(t_stack **stack_b, bool print);

/*ROTATE*/
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);
void	ra(t_stack **stack_a, bool print);
void	rb(t_stack **stack_b, bool print);

/*STACK HANDLING*/
t_stack	*stacklast(t_stack **stack);
int		stacklength(t_stack *stack);
void	stackadd(t_stack **stack, t_stack *new, bool back);
t_stack	*stacknew(int value);
t_stack	*stackdup(t_stack *original);

/*SWAP*/
void	ss(t_stack **stack_a, t_stack **stack_b, bool print);
void	sa(t_stack **stack_a, bool print);
void	sb(t_stack **stack_b, bool print);

#endif
