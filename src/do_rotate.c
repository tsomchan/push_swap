/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:17:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 22:18:56y tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_rotate(t_node **node)
{
	t_node	*tmp;
	t_node	*first;
	t_node	*last;

	tmp = *node;
	while (tmp->next)
		tmp = tmp->next;
	last = *node;
	first = (*node)->next;
	*node = first;
	tmp->next = last;
	last->next = NULL;
}

void	do_ra(t_stack *stack)
{
	do_rotate(&stack->a);
	write(1, "ra\n", 3);
}

void	do_rb(t_stack *stack)
{
	do_rotate(&stack->b);
	write(1, "rb\n", 3);
}

void	do_rr(t_stack *stack)
{
	do_rotate(&stack->a);
	do_rotate(&stack->b);
	write(1, "rr\n", 3);
}

/* void	do_rotate(t_node *node)
	//int	tmp;

	//if (!node->next)
	//	return ;
	//tmp = node->val;
	//while (node->next)
	//{
	//	node->val = node->next->val;
	//	node = node->next;
	//}
	//node->val = tmp;
*/