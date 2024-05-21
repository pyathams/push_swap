/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:42:58 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/21 21:17:32 by pyathams         ###   ########.fr       */
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
