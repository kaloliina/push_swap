/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:14:30 by khiidenh          #+#    #+#             */
/*   Updated: 2025/01/23 18:42:59 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **source)
{
	t_node	*temp;

	if (*source == NULL)
		return ;
	temp = *source;
	*source = (*source)->next;
	if (*source != NULL)
		(*source)->prev = NULL;
	temp->next = *dest;
	temp->prev = NULL;
	if (*dest != NULL)
		(*dest)-> prev = temp;
	*dest = temp;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}
