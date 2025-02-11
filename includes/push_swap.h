/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiidenh <khiidenh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:01:59 by khiidenh          #+#    #+#             */
/*   Updated: 2025/01/24 11:56:04 by khiidenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				data;
	int				pos;
	bool			cheapest;
	bool			median;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}	t_node;

/*Error handling*/
bool	check_is_duplicate(t_node *stack, int n);
bool	check_is_digit(char *str);
void	exit_program(t_node **stack, char **args, int success);

/*Initialize stack*/
char	**parse_arguments(int argc, char *argv[], t_node *stack_a);
void	initialize_stack_a(char **args, int arg_count, t_node **stack_a);

/*Sort*/
void	sort_stacks(t_node **stack_a, t_node **stack_b, int length);
void	sort_three(t_node **stack_a);

/*Transition to b*/
void	set_all_targets_in_b(t_node *stack_a, t_node *stack_b);
void	move_a_to_b(t_node **stack_a, t_node **stack_b);

/*Transition to a*/
void	set_target_in_a(t_node *stack_a, t_node *node_b);
void	move_b_to_a(t_node **stack_a, t_node **stack_b);

/*Utility functions*/
int		stack_length(t_node *stack);
bool	stack_sorted(t_node *stack);
void	find_index_and_median(t_node *stack);

/*Operations*/
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif
