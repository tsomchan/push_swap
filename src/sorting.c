/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:13:04 by tsomchan          #+#    #+#             */
/*   Updated: 2024/03/08 19:06:35 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*current_stack_order(t_stack *stack, t_node **stack_name)
{
	t_node	*head;
	t_node	*min_node;
	t_node	*min_prev;
	t_node	*tmp;

	dupe_stack(stack, *stack_name, &(stack->order));
	min_prev = NULL;
	head = stack->order;
	while (head->next != stack->order)
	{
		min_node = head;
		tmp = head;
		while (tmp->next != head)
		{
			tmp = tmp->next;
			if (tmp->val < min_node->val
				&& (!min_prev || tmp->val > min_prev->val))
				min_node = tmp;
		}
		swap_nodes_value(&(min_node), &(head));
		min_prev = head;
		head = head->next;
	}
	return (stack->order);
}

void	find_median(t_stack *stack, t_node **stack_name)
{
	t_node	*tmp;
	int		node_count;
	int		median_count;
	int		node_current;
	int		median;

	node_count = count_nodes(*stack_name);
	current_stack_order(stack, stack_name);
	median_count = (node_count / 2) + (node_count % 2);
	node_current = 1;
	tmp = stack->order;
	while (node_current < median_count)
	{
		tmp = tmp->next;
		node_current++;
	}
	stack->median = tmp->val;
}

/*
	5 -> 3
	(5 / 2) + 1 = 3
	6 -> 3
*/