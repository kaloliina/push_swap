/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:01:11 by khiidenh          #+#    #+#             */
/*   Updated: 2025/02/13 17:09:19 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atoll(const char *nptr)
{
	int				i;
	int				check;
	long long int	result;

	i = 0;
	check = 1;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			check = -1 * check;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * check);
}

static void	append(t_node **head, int data, char **args)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit_program(head, args, 0);
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

void	initialize_stack_a(char **args, int arg_count, t_node **stack_a)
{
	long long int	nbr;
	int				i;

	i = 0;
	while (i < arg_count)
	{
		if (check_is_digit(args[i]) == false)
			exit_program(stack_a, args, 0);
		nbr = ft_atoll(args[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			exit_program(stack_a, args, 0);
		if (check_is_duplicate(*stack_a, nbr) == true)
			exit_program(stack_a, args, 0);
		append(stack_a, nbr, args);
		i++;
	}
}

char	**parse_arguments(int argc, char *argv[], t_node *stack_a)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL || args[0] == NULL)
			exit_program(&stack_a, args, 0);
	}
	else
	{
		args = malloc(argc * sizeof(char *));
		if (args == NULL)
			exit_program(&stack_a, args, 0);
		while (argv[i + 1] != NULL)
		{
			args[i] = ft_strdup(argv[i + 1]);
			if (args[i] == NULL)
				exit_program(&stack_a, args, 0);
			i++;
		}
		args[i] = NULL;
	}
	return (args);
}
