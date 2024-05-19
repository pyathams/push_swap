/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:09 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/19 17:20:39 by pyathams         ###   ########.fr       */
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

int				error_synatax(char *str_n);
void			free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *a, int n);
void			free_errors(t_stack_node **a);
t_stack_node	*find_last(t_stack_node *stack);
void			free_split(char **split_result);

char			**split(char *s, char c);

void			init_stack_a(t_stack_node **a, char **argv);

#endif