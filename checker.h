/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:08:33 by aternero          #+#    #+#             */
/*   Updated: 2024/11/21 12:44:01 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stddef.h>
# include "push_swap.h"
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4069
# endif

/* typedef struct s_stack
{
	int					value;
	int					index;
	int					position;
	int					target;
	int					cost_a;
	int					cost_b;
	int					cost;
	struct s_stack	*next;
}					t_stack;
 */
/*CHECKER*/
bool		reader(char *bso, t_stack **stack_a, t_stack **stack_b);
void		input_checker(int argc, char **argv, t_stack **stack_a);
int			main(int ac, char **agv);

/*GET_NEXT_LINE*/
char		*get_next_line(int fd);

#endif
