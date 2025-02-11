/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:52:50 by khiidenh          #+#    #+#             */
/*   Updated: 2025/01/23 18:05:02 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		arg_count;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	arg_count = 0;
	if (argc == 1)
		return (1);
	args = parse_arguments(argc, argv, stack_a);
	while (args[arg_count] != NULL)
		arg_count++;
	initialize_stack_a(args, arg_count, &stack_a);
	if (stack_sorted(stack_a) == 0)
	{
		if (stack_length(stack_a) == 2)
			sa(&stack_a);
		else if (stack_length(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b, stack_length(stack_a));
	}
	exit_program(&stack_a, args, 1);
	return (0);
}
