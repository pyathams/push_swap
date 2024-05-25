/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:48:50 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/25 16:04:55 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atol(char *str)
{
	long long int	result;
	int				sign;

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
	{
		result = result * 10 + (*str++ - '0');
		if (result == LLONG_MAX / 10 && sign == -1 && *str == '8')
			return (LLONG_MIN);
	}
	return (result * sign);
}

void	append_node(t_stack_node **stack, int n)
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
	long long int	n;
	int				i;

	i = 0;
	while (argv[i])
	{
		if (error_synatax(argv[i]))
			free_errors(a, argv, argc);
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(a, argv, argc);
		if (error_duplicate(*a, (int)n))
			free_errors(a, argv, argc);
		append_node (a, (int)n);
		i++;
	}
}
