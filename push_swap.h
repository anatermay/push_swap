/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:25:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/09 13:30:54 by aternero         ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*0_PS_MF_MAIN.C FILE*/
void	ft_argv_extraction(int argc, char **argv, t_stack **stack_a);
int		main(int argc, char **argv);

/*0_PS_MF_PUSH_SWAP.C FILE*/
void	ft_push_swap(t_stack *stack_a, t_stack *stack_b);

/*0_PS_MF_CHECKER.C FILE*/
void	ft_error(int print);
int		ft_sorted(t_stack *stack_a);
int		ft_duplicates(t_stack *stack_a);
void	ft_checker(t_stack *stack_a);
void	ft_valid_numbers(char *str);

/*1_PS_SH_1.C FILE*/
void	ft_stackadd(t_stack **stack, t_stack *add);
t_stack	*ft_stacklast(t_stack **stack);
int		ft_stacklength(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_free_both_stack(t_stack **stack_a, t_stack **stack_b);

/*1_PS_SH_2.C FILE*/

/*2_PS_CMP_LIBFT.C FILE*/
int		ft_isdigit(int c);
int		ft_spc(char str);
int		ft_atoi(const char *str);

/*3_PS_BSO_SWAP.C FILE*/
void	ft_ss(t_stack **a, t_stack **b, int print);
void	ft_sa_sb(t_stack **stack, int print, int aorb);

/*3_PS_BSO_ROTATE.C FILE*/
void	ft_rr(t_stack **a, t_stack **b, int print);
void	ft_ra_rb(t_stack **stack, int print, int aorb);

/*3_PS_BSO_REVERSE_ROTATE.C FILE*/
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	ft_rra_rrb(t_stack **stack, int print, int aorb);

/*3_PS_BSO_PUSH.C FILE*/
void	ft_pa_pb(t_stack **dst, t_stack **src, int print, int aorb);

/*3_PS_MORE_BSO.C FILE*/
void	ft_aorb_rot(t_stack **stack, int cost, int aorb);
void	ft_rr_rot(t_stack **a, t_stack **b, int acost, int bcost);

/*4_PS_IF_THREE_ARGS.C FILE*/
void	if_three_args(t_stack **stack_a);

/*4_PS_IF_FOUR_ARGS.C FILE*/
void	if_four_args(t_stack **stack_a, t_stack **stack_b);

/*4_PS_IF_FIVE_ARGS.C FILE*/
void	if_five_args(t_stack **stack_a, t_stack **stack_b);

/*4_PS_MORE_INA.C FILE*/
void	ft_positioning(t_stack **stack_a);
int		ft_min_position(t_stack **stack_a);
int		ft_min_value(t_stack **stack_a);
int		ft_max_position(t_stack **stack_a);
int		ft_max_value(t_stack **stack_a);

/* 
GLOSSARY OF ABBREVIATIONS
	- BSO: Basic Stacks Operations
	- AORB: A or B
	- ACOST: A cost
	- BCOST: B cost
	- PS: Push Swap
	- SH: Stack Handling
	- CMP: Complementary
	- MF: Main Functions
	- TEMP: Temporary
	- LIBFT: Libft Functions [FUNCTIONS LIBRARY]
GLOSSARY OF FILES ABREVIATIONS
	- 0__PS_MF: Push Swap Main Functions
	- 1_PS_SH: Push Swap Stack Handling
	- 2_PS_CMP: Push Swap Complementary
	- 3_PS_BSO: Push Swap Basic Stacks Operations
	- 4_PS_: Push Swap If "Number" Arguments
BASIC STACKS OPERATIONS USE AORB
	int AORB -> a = 0 && b = 1
		- IF PA -> dst = t_stack **a
		&& src = t_stack **b;
		- IF PB -> dst = t_stack **b
		&& src = t_stack **a;
 */

#endif