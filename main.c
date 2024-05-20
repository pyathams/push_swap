/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:19:24 by pyathams          #+#    #+#             */
/*   Updated: 2024/05/20 13:13:29 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	// t_stack_node	*b;
	t_stack_node	*tmp;
	char **modified_argv;

	modified_argv = NULL;
	a = NULL;
	// b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		modified_argv = split(argv[1], ' ');
	if (argc == 2)
		init_stack_a(&a, modified_argv);
	else
		init_stack_a(&a, argv + 1);
	while (a)
	{
		tmp = a -> next;
		ft_printf("%d \n", a -> nbr);
		free(a);
		a = tmp;
	}
	if (argc == 2)
		free_split(modified_argv);
	free_stack(&a);
	return (0);
}
