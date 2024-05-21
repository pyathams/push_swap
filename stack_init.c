/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:48:50 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/21 18:06:20 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_stack(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

int	stack_len(t_stack_node	*a)
{
	int	count;

	count = 0;
	while (a)
	{
		a = a->next;
		count++;
	}
	return (count);
}

int	ft_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node ->next = NULL;
	node ->nbr = n;
	if (!(*stack))
	{
		*stack = node;
		node ->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node ->next = node;
		node ->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_synatax(argv[i]))
			free_errors(a, argv, argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, argv, argc);
		if (error_duplicate(*a, (int)n))
			free_errors(a, argv, argc);
		append_node (a, (int)n);
		i++;
	}
}
