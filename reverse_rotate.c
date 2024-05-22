/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:42:23 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/22 19:46:16 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*reverse_rotate_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	reverse_rotate_node = find_last(*stack);
	if (reverse_rotate_node ->prev->next != NULL)
		reverse_rotate_node->prev->next = NULL;
	reverse_rotate_node->prev = NULL;
	reverse_rotate_node->next = *stack;
	(*stack)->prev = reverse_rotate_node;
	*stack = reverse_rotate_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rev_rotate_both(t_stack_node	**a,
				t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	write (1, "rrr\n", 4);
}
