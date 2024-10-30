/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:25:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/30 12:07:29 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int				value;
	int				position;
	int				p_side;
	int				target;
	int				t_side;
	int				cost;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*INDEX*/
	// 00.	push_swap.c
	// 01.	checker.c
	// 02.	libft_atoi.c
	// 03.	stack_handling.c
	// 04.	BASIC STACK OPERATIONS
				// 00.	push.c
				// 01.	reverse_rotate.c
				// 02.	rotate.c
				// 03.	swap.c
	// 05.	VALUES
				// min_value_handling.c
				// max_value_handling.c
	// 06.	IF 'NUMBER' ARGS
				//	if_less_than_five_args.c
	// 07.	IF_SEMI_SORTED.C
	// 08.	ALGORITHM
				// 00.	MAIN.C
				// 01.	PB.C
				// 02.	PA.C

/*PUSH_SWAP.C*/
void			ps_prev_algorithm(t_stack **stack_a, t_stack **stack_b);
void			push_swap(t_stack *stack_a, t_stack *stack_b);
void			argv_extraction(int argc, char **argv, t_stack **stack_a);
int				main(int argc, char **argv);

/*CHECKER.C*/
void			error(int print);
int				sorted(t_stack *stack_a);
int				duplicates(t_stack *stack_a);
void			checker(t_stack *stack_a);
void			valid_numbers(char *str);

/*LIBFT_ATOI.C*/
int				isdigit(int c);
int				spc(char str);
int				atoi(const char *str);

/*STACK_HANDLING.C*/
void			stackadd(t_stack **stack, t_stack *add);
t_stack			*stacklast(t_stack **stack);
int				stacklength(t_stack *stack);
void			free_stack(t_stack **stack);
void			free_both_stack(t_stack **stack_a, t_stack **stack_b);

/*BASIC STACK OPERATIONS*/
	// push.c
void			pa_pb(t_stack **dst, t_stack **src, int print, int aorb);
	// reverse_rotate.c
void			rrr(t_stack **a, t_stack **b, int print);
void			rra_rrb(t_stack **stack, int print, int aorb);
	// rotate.c
void			rr(t_stack **a, t_stack **b, int print);
void			ra_rb(t_stack **stack, int print, int aorb);
	// swap.c
void			ss(t_stack **a, t_stack **b, int print);
void			sa_sb(t_stack **stack, int print, int aorb);

/*VALUES*/
	// min_value_handling.c
void			min_positioning(t_stack **stack_a);
int				min_position(t_stack **stack_a);
int				min_value(t_stack **stack_a);
	// max_value_handling.c
void			max_positioning(t_stack **stack_a);
int				max_position(t_stack **stack_a);
int				max_value(t_stack **stack_a);

/*IF 'NUMBER' ARGS*/
	// if_less_than_five_args.c
void			if_three_args(t_stack **stack_a);
void			if_four_args(t_stack **stack_a, t_stack **stack_b);
void			if_five_args(t_stack **stack_a, t_stack **stack_b);

/*IF_SEMI_SORTED.C*/
void			sort_inversed(t_stack **stack_a, t_stack **stack_b);
int				if_partially_sorted(t_stack **stack_a);
int				if_partially_and_inversely_sorted(t_stack **stack_a);
int				if_inversely_sorted(t_stack **stack_a);

/* 5_PS_ALGORITHM.C FILE
int				side_calculator(t_stack **stack, int nbr);
void			continue_positioning_stack_b(t_stack **b, int ps, int ts);
void			continue_positioning_stack_a(t_stack **a, int ps, int ts);
void			continue_positioning_both(t_stack **stack_a, t_stack **stack_b);
void			min_cost_positioning(t_stack **stack_a, t_stack **stack_b);
int				target_calculator(t_stack **stack, int nbr);
int				position_calculator(t_stack **stack, int nbr);
int				cost_calculator(t_stack **stack_a, t_stack **stack_b);
void			transaction_to_b(t_stack **stack_a, t_stack **stack_b);
void			algorithm(t_stack **stack_a, t_stack **stack_b); */

/* UTILS*/
int				be_positive(int n);
void			aorb_rot(t_stack **stack, int cost, int aorb);
void			rr_rot(t_stack **a, t_stack **b, int acost, int bcost);
void			rrr_rot(t_stack **a, t_stack **b, int acost, int bcost);

/* PRINT STACKS */
void			print_stack(t_stack *stack, int sum_up);
void			print_stacks(t_stack *stack_a, t_stack *stack_b, int sum_up);

#endif