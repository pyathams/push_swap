/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:42:58 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/22 13:48:26 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_we_push;

	node_we_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_we_push -> prev = NULL;
	if (!(*dest))
	{
		*dest = node_we_push;
		node_we_push -> next = NULL;
	}
	else
	{
		node_we_push -> next = (*dest);
		node_we_push -> next -> prev = node_we_push;
		*dest = node_we_push;
	}
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}