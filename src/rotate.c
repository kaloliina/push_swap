/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:07:25 by khiidenh          #+#    #+#             */
/*   Updated: 2025/02/13 17:05:20 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last;
	t_node	*new_head;

	last = *stack;
	new_head = (*stack)->next;
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *stack;
	(*stack)->prev = last;
	(*stack)->next = NULL;
	*stack = new_head;
	(*stack)->prev = NULL;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
