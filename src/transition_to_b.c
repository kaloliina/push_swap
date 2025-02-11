/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_to_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:33:10 by khiidenh          #+#    #+#             */
/*   Updated: 2025/01/23 18:36:37 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_moves(t_node *node_a, t_node *stack_a, t_node *stack_b)
{
	int	moves;
	int	moves_a;
	int	moves_b;

	if (node_a->median == true)
		moves_a = node_a->pos;
	if (node_a->median == false)
		moves_a = stack_length(stack_a) - node_a->pos;
	if (node_a->target_node->median == true)
		moves_b = node_a->target_node->pos;
	if (node_a->target_node->median == false)
		moves_b = stack_length(stack_b) - node_a->target_node->pos;
	moves = moves_a + moves_b;
	if ((node_a->median == true && node_a->target_node->median == true)
		|| (node_a->median == false && node_a->target_node->median == false))
	{
		if (moves_a > moves_b)
			moves = moves_a;
		else
			moves = moves_b;
	}
	return (moves);
}

t_node	*get_cheapest(t_node *stack_a, t_node *stack_b)
{
	int		moves;
	int		cheapest_found;
	t_node	*current;
	t_node	*cheapest;

	current = stack_a;
	cheapest = NULL;
	while (current != NULL)
	{
		moves = calculate_moves(current, stack_a, stack_b);
		if (cheapest == NULL || moves < cheapest_found)
		{
			cheapest_found = moves;
			cheapest = current;
		}
		current = current->next;
	}
	if (cheapest != NULL)
		cheapest->cheapest = true;
	return (cheapest);
}

void	move_a_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*stack_a, *stack_b);
	while (cheapest->median == true && cheapest->target_node->median == true
		&& (*stack_a) != cheapest && (*stack_b) != cheapest->target_node)
		rr(stack_a, stack_b);
	while (cheapest->median == false && cheapest->target_node->median == false
		&& (*stack_a) != cheapest && (*stack_b) != cheapest->target_node)
		rrr(stack_a, stack_b);
	while ((*stack_a) != cheapest && cheapest->median == true)
		ra(stack_a);
	while ((*stack_a) != cheapest && cheapest->median == false)
		rra(stack_a);
	while ((*stack_b) != cheapest->target_node
		&& cheapest->target_node->median == true)
		rb(stack_b);
	while ((*stack_b) != cheapest->target_node
		&& cheapest->target_node->median == false)
		rrb(stack_b);
	pb(stack_a, stack_b);
}

void	set_target_in_b(t_node *stack_b, t_node *node_a)
{
	t_node	*curr;
	t_node	*pos;
	int		max;

	curr = stack_b;
	max = INT_MIN;
	pos = NULL;
	node_a->target_node = NULL;
	while (curr != NULL)
	{
		if ((curr->data < node_a->data && node_a->target_node == NULL)
			|| (node_a->target_node != NULL
				&& curr->data > node_a->target_node->data
				&& curr->data < node_a->data))
			node_a->target_node = curr;
		if (max < curr->data)
		{
			max = curr->data;
			pos = curr;
		}
		curr = curr->next;
	}
	if (node_a->target_node == NULL)
		node_a->target_node = pos;
}

void	set_all_targets_in_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;

	current = stack_a;
	while (current != NULL)
	{
		set_target_in_b(stack_b, current);
		current = current->next;
	}
}
