/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:02:09 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/22 19:46:46 by pyathams         ###   ########.fr       */
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
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;					
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//for passing intial parameters for making stack..
int						intial(char **argv, int argc, t_stack_node **a);

//if we have only 1 argument with number we use ft_split of libft 
//convert in modified_strings_array and free it after using it to make stack
char					**split(char *s, char c);
void					free_split(char **split_result);

//checking error during making stack from argment passing..
int						error_synatax(char *str_n);
void					free_stack(t_stack_node **stack);
int						error_duplicate(t_stack_node *a, int n);
void					free_errors(t_stack_node **a, char **argv, int argc);

//creating stack from given arguments
void					init_stack_a(t_stack_node **a, char **argv, int argc);
int						sorted_stack(t_stack_node *a);
int						ft_atol(char *str);
void					append_node(t_stack_node **stack, int n);

//stack utilis for three_list_sort and push_swap
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*find_highest(t_stack_node *stack);
t_stack_node			*find_lowest(t_stack_node	*stack);
int						stack_len(t_stack_node	*a);

//sorting if we have only three_numbers_in_arguments
void					three_list_sort(t_stack_node	**a);

void	inti_nodes_a(t_stack_node *a, t_stack_node *b);
void	current_index(t_stack_node *stack);
void	set_target_a(t_stack_node *a, t_stack_node *b);
void	cost_analysis_a(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node	*stack);

void	set_target_b(t_stack_node *a, t_stack_node *b);
void	inti_nodes_b(t_stack_node *a, t_stack_node *b);

void	push_swap(t_stack_node **a, t_stack_node **b);

void	move_a_to_b(t_stack_node **a, t_stack_node **b);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, 
					t_stack_node *top_node, char stack_name);
void	move_b_to_a(t_stack_node **a, t_stack_node **b);
void	min_on_top(t_stack_node **a);


//push_swap commands
void					sa(t_stack_node	**a);
void					ra(t_stack_node **a);
void					rb(t_stack_node **b);
void					rra(t_stack_node **a);
void					pb(t_stack_node **b, t_stack_node **a);
void					pa(t_stack_node **a, t_stack_node **b);
void					rev_rotate_both(t_stack_node	**a,
							t_stack_node **b, t_stack_node *cheapest_node);
void					rotate_both(t_stack_node **a,
							t_stack_node **b, t_stack_node *cheapest_node);
void					rrb(t_stack_node **b);
#endif