/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:09:53 by khiidenh          #+#    #+#             */
/*   Updated: 2025/02/13 17:08:13 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	if (stack_sorted(*stack_a) == 1)
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->data)
	{
		ra(stack_a);
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if ((*stack_a)->next->data > (*stack_a)->data
		&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		rra(stack_a);
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else
		sa(stack_a);
}

static void	min_to_top(t_node **stack_a)
{
	int		moves;
	t_node	*curr;
	t_node	*min;

	curr = (*stack_a);
	min = NULL;
	if (stack_sorted(*stack_a) == 1)
		return ;
	while (curr != NULL)
	{
		if (min == NULL || curr->data < min->data)
			min = curr;
		curr = curr->next;
	}
	if (min->median == true)
		moves = min->pos;
	else
		moves = stack_length(*stack_a) - min->pos;
	while (moves-- > 0)
	{
		if (min->median == true)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_stacks(t_node **stack_a, t_node **stack_b, int length)
{
	if (length-- > 3 && stack_sorted(*stack_a) == 0)
		pb(stack_a, stack_b);
	if (length-- > 3 && stack_sorted(*stack_a) == 0)
		pb(stack_a, stack_b);
	while (length > 3 && stack_sorted(*stack_a) == 0)
	{
		find_index_and_median(*stack_a);
		find_index_and_median(*stack_b);
		set_all_targets_in_b(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
		length--;
	}
	sort_three(stack_a);
	while ((*stack_b) != NULL)
	{
		find_index_and_median(*stack_a);
		find_index_and_median(*stack_b);
		set_target_in_a(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	find_index_and_median(*stack_a);
	min_to_top(stack_a);
}
