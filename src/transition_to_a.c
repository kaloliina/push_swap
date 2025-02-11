/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:48:41 by khiidenh          #+#    #+#             */
/*   Updated: 2025/01/23 18:41:57 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_node **stack_a, t_node **stack_b)
{
	if (*stack_b == NULL)
		return ;
	while ((*stack_a) != (*stack_b)->target_node)
	{
		if ((*stack_b)->target_node->median == true)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pa(stack_a, stack_b);
}

void	set_target_in_a(t_node *stack_a, t_node *node_b)
{
	t_node	*curr;
	t_node	*pos;
	int		min;

	min = INT_MAX;
	pos = NULL;
	curr = stack_a;
	node_b->target_node = NULL;
	while (curr != NULL)
	{
		if ((curr->data > node_b->data && node_b->target_node == NULL)
			|| (node_b->target_node != NULL
				&& curr->data < node_b->target_node->data
				&& curr->data > node_b->data))
			node_b->target_node = curr;
		if (min > curr->data)
		{
			min = curr->data;
			pos = curr;
		}
		curr = curr->next;
	}
	if (node_b->target_node == NULL)
		node_b->target_node = pos;
}
