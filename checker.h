/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:08:33 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 20:25:58 by aternero         ###   ########.fr       */
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

/*CHECKER*/
bool	reading_comprehension(char *bso, t_stack *stack_a, t_stack *stack_b);
void	input_reader(int argc, char **argv, t_stack *stack_a);
int		main(int argc, char **argv);

/*GET NEXT LINE*/
char	*get_next_line(int fd);

/*LIBFT*/
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
