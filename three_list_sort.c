/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_list_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:25:06 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/21 21:17:46 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = stack->nbr;
	highest_node = stack;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	three_list_sort(t_stack_node	**a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
