/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:26:38 by khiidenh          #+#    #+#             */
/*   Updated: 2025/01/23 18:39:35 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_node *stack)
{
	int		length;
	t_node	*curr;

	length = 0;
	curr = stack;
	while (curr != NULL)
	{
		curr = curr->next;
		length++;
	}
	return (length);
}

bool	stack_sorted(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->data < curr->next->data)
			curr = curr->next;
		else
			return (false);
	}
	return (true);
}

void	find_index_and_median(t_node *stack)
{
	int		i;
	int		median;
	t_node	*curr;

	i = 0;
	median = stack_length(stack) / 2;
	curr = stack;
	while (curr != NULL)
	{
		curr->pos = i;
		if (i <= median)
			curr->median = true;
		else
			curr->median = false;
		curr = curr->next;
		i++;
	}
}
