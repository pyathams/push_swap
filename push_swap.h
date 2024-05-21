/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:09 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/21 21:04:35 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/inc/libft.h"
# include "libft/inc/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				intial_condition(char **argv, int argc, t_stack_node **a);
int				error_synatax(char *str_n);
void			free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *a, int n);
void			free_errors(t_stack_node **a, char **argv, int argc);
t_stack_node	*find_last(t_stack_node *stack);
void			free_split(char **split_result);

char			**split(char *s, char c);

void			init_stack_a(t_stack_node **a, char **argv, int argc);
int				sorted_stack(t_stack_node *a);
int				stack_len(t_stack_node	*a);

void			three_list_sort(t_stack_node	**a);

void			sa(t_stack_node	**a);
void			ra(t_stack_node **a);
void			rra(t_stack_node **a);

#endif