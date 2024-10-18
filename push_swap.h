/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:25:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/18 18:09:01 by aternero         ###   ########.fr       */
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
	int 			p_side;
	int 			target;
	int 			t_side;
	int 			aorb;
	int 			length_a;
	int 			length_b;
	char			 **cmd;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*0_PS_MF_MAIN.C FILE*/
void	argv_extraction(int argc, char **argv, t_stack **stack_a);
int		main(int argc, char **argv);

/*0_PS_MF_PUSH_SWAP.C FILE*/
void	push_swap(t_stack *stack_a, t_stack *stack_b);

/*0_PS_MF_CHECKER.C FILE*/
void	error(int print);
int		sorted(t_stack *stack_a);
int		duplicates(t_stack *stack_a);
void	checker(t_stack *stack_a);
void	valid_numbers(char *str);

/*1_PS_SH_1.C FILE*/
void	stackadd(t_stack **stack, t_stack *add);
t_stack	*stacklast(t_stack **stack);
int		stacklength(t_stack *stack);
void	free_stack(t_stack **stack);
void	free_both_stack(t_stack **stack_a, t_stack **stack_b);

/*2_PS_CMP_LIBFT.C FILE*/
int		isdigit(int c);
int		spc(char str);
int		atoi(const char *str);

/*3_PS_BSO_SWAP.C FILE*/
void	ss(t_stack **a, t_stack **b, int print);
void	sa_sb(t_stack **stack, int print, int aorb);

/*3_PS_BSO_ROTATE.C FILE*/
void	rr(t_stack **a, t_stack **b, int print);
void	ra_rb(t_stack **stack, int print, int aorb);

/*3_PS_BSO_REVERSE_ROTATE.C FILE*/
void	rrr(t_stack **a, t_stack **b, int print);
void	rra_rrb(t_stack **stack, int print, int aorb);

/*3_PS_BSO_PUSH.C FILE*/
void	pa_pb(t_stack **dst, t_stack **src, int print, int aorb);

/*3_PS_MORE_BSO.C FILE*/
void	aorb_rot(t_stack **stack, int cost, int aorb);
void	rr_rot(t_stack **a, t_stack **b, int acost, int bcost);

/*4_PS_IF_THREE_ARGS.C FILE*/
void	if_three_args(t_stack **stack_a);

/*4_PS_IF_FOUR_ARGS.C FILE*/
void	if_four_args(t_stack **stack_a, t_stack **stack_b);

/*4_PS_IF_FIVE_ARGS.C FILE*/
void	if_five_args(t_stack **stack_a, t_stack **stack_b);

/*4_PS_MORE_INA.C FILE*/
void	min_positioning(t_stack **stack_a);
int		min_position(t_stack **stack_a);
int		min_value(t_stack **stack_a);
int		max_position(t_stack **stack_a);
int		max_value(t_stack **stack_a);

/*4_PS_IF_PARTIALLY_ORDERED.C FILE*/
int		if_partially_sorted(t_stack **stack_a);
int		if_partially_and_inversely_sorted(t_stack **stack_a);
int		if_inversely_sorted(t_stack **stack_a);
void	sort_inversed(t_stack **stack_a, t_stack **stack_b);

/*5_PS_ALGORITHM_1.C FILE*/
void	stack_reset(t_stack **stack_a, t_stack **stack_b);
void	stack_a_reset(t_stack **stack_a, t_stack **stack_b);
void	stack_b_reset(t_stack **stack_a, t_stack **stack_b);
int		find_target_position(t_stack *stack, t_stack **stack_cmp);
int		find_position(t_stack *stack, t_stack **stack_cmp);

#endif