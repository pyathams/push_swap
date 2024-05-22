/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:19:27 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/22 19:50:29 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len_stack_a;

	len_stack_a = stack_len(*a);
	if (len_stack_a-- > 3 && !(sorted_stack(*a)))
		pb(b, a);
	if (len_stack_a-- > 3 && !(sorted_stack(*a)))
		pb(b, a);
	while (len_stack_a-- > 3 && !(sorted_stack(*a)))
	{
		inti_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	three_list_sort(a);
	while (*b)
	{
		inti_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
