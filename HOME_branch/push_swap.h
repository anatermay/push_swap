/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:52:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 22:05:24 by aternero         ###   ########.fr       */
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
	int				cost;
	int				side; // Up [0] or Down[1]
	int				cheapest; // True[1] or False[0]
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*PUSH_SWAP*/
int				main(int argc, char **argv);
void			argc_checker(int argc, char **argv);
void			argv_extraction(int argc, char **argv, t_stack **stack_a);
void			push_swap(t_stack *stack_a, t_stack *stack_b);
void			prev_algorithm(t_stack **stack_a, t_stack **stack_b);

/*CHECKER*/
void			error(int print);
int				sorted(t_stack *stack_a);
int				duplicates(t_stack *stack_a);
void			checker(t_stack *stack_a);
void			valid_numbers(char *str);

/*STACK*/
void			stackadd(t_stack **stack, t_stack *add);
t_stack			*stacklast(t_stack **stack);
int				stacklength(t_stack *stack);
void			free_stack(t_stack **stack);
void			free_both_stack(t_stack **stack_a, t_stack **stack_b);

/*INSTRUCTIONS*/
	// PUSH
void			pa_pb(t_stack **dst, t_stack **src, int print, int aorb);
	// REVERSE ROTATE
void			rrr(t_stack **a, t_stack **b, int print);
void			rra_rrb(t_stack **stack, int print, int aorb);
	// ROTATE
void			rr(t_stack **a, t_stack **b, int print);
void			ra_rb(t_stack **stack, int print, int aorb);
	// SWAP
void			ss(t_stack **a, t_stack **b, int print);
void			sa_sb(t_stack **stack, int print, int aorb);

/*IF_NBR_ARGS*/
void			if_three_args(t_stack **stack_a);
void			if_four_args(t_stack **stack_a, t_stack **stack_b);
void			if_five_args(t_stack **stack_a, t_stack **stack_b);

/*MIN*/
t_stack			*min_node(t_stack **stack);
void			min_positioning(t_stack **stack);
int				min_position(t_stack **stack);
int				min_value(t_stack **stack);

/*MAX*/
t_stack			*max_node(t_stack **stack);
void			max_positioning(t_stack **stack);
int				max_position(t_stack **stack);
int				max_value(t_stack **stack);

/*SEMI_SORTED*/
	// SEMI_SORTED_CHECK
int				if_inversely_sorted(t_stack **stack_a);
int				if_partially_and_inversely_sorted(t_stack **stack_a);
int				if_partially_sorted(t_stack **stack_a);
	// INVERSED SORTING
void			sort_inversed(t_stack **stack_a, t_stack **stack_b);

/*LIBFT*/
	// ATOI
int				isdigit(int c);
int				spc(char str);
int				atoi(const char *str);
	// SPLIT
void			ft_free(char **str, int letter);
void			fill_words(const char *s, char c, char **str, size_t *length);
size_t			word_counter(const char *s, char c);
char			**allocate_memory(const char *s, char c);
char			**split(char const *s, char c);
	// SPLIT CONTINUE...
size_t			strlen(const char *s);
size_t			strlcpy(char *dst, const char *src, size_t dstsize);
char			*strdup(const char *s1);
char			*substr(char const *s, unsigned int start, size_t len);

/*TURK ALGORITHM*/
	// TURK_ALGORITHM FILE 0
void			turk_algorithm(t_stack **stack_a, t_stack **stack_b);
	// TURK_ALGORITHM FILE 1: Utils
void			prep_for_push(t_stack **stack, t_stack *min_cost, int aorb);
t_stack			*get_cheapest(t_stack *stack);
void			set_cheapest(t_stack *stack);
void			current_index(t_stack *stack);
	// TURK_ALGORITHM FILE 2: Sorting back from A to B
void			move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void			set_target_stack_a(t_stack *stack_a, t_stack *stack_b);
void		cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
void			init_nodes_stack_a(t_stack *stack_a, t_stack *stack_b);
	// TURK_ALGORITHM FILE 3: Sorting from B to A
void		move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void			set_target_stack_b(t_stack *stack_a, t_stack *stack_b);
void			init_nodes_stack_b(t_stack *stack_a, t_stack *stack_b);

/*UTILS*/
void			aorb_rot(t_stack **stack, int cost, int aorb);
void			rr_rot(t_stack **a, t_stack **b, int acost, int bcost);
int				be_positive(int n);
int				str_chr(char *str, char c);

#endif