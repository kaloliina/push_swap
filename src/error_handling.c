/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:48:27 by khiidenh          #+#    #+#             */
/*   Updated: 2025/01/23 18:49:54 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (false);
		i++;
	}
	return (true);
}

bool	check_is_duplicate(t_node *stack, int n)
{
	t_node	*curr;

	curr = stack;
	while (curr != NULL)
	{
		if (curr->data == n)
			return (true);
		curr = curr->next;
	}
	return (false);
}

void	exit_program(t_node **stack, char **args, int success)
{
	t_node	*curr;
	int		i;

	if (stack != NULL && (*stack) != NULL)
	{
		while ((*stack) != NULL)
		{
			curr = (*stack);
			(*stack) = (*stack)->next;
			free (curr);
		}
	}
	if (args != NULL)
	{
		i = 0;
		while (args[i] != NULL)
		{
			free (args[i]);
			i++;
		}
		free (args);
	}
	if (success == 0)
		write(2, "Error\n", 6);
	exit(1);
}
