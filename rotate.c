/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:25:27 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/21 18:45:05 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*rotate_node;
	t_stack_node	*last_node;

	if (stack == NULL || *stack == NULL)
		return ;
	rotate_node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node = find_last(*stack);
	last_node->next = rotate_node;
	rotate_node->prev = last_node;
	rotate_node->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
