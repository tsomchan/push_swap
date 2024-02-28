/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:59:05 by tsomchan          #+#    #+#             */
/*   Updated: 2024/02/28 20:10:22 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*start_stack(t_stack *stack)
{
	if (!stack)
		stack = malloc(sizeof(t_stack));
	stack->a = NULL;
	stack->b = NULL;
	return (stack);
}

void	input_stack(t_stack *stack, char **argv)
{
	int		num;

	argv++;
	while (*argv)
	{
		num = atoi(*argv);
		add_node_last(&stack->a, nodenew(num));
		print_node(stack->a, "stack a");
		argv++;
	}
}

/*
if(*argv != ' ')
{
	len = ft_strlen(ft_strchr(argv, ' '));
	//if (!stack->a)
	stack.a = nodenew(ft_atoi(ft_substr(argv, 0, len)));
	//else
	//	stack->a->next = nodenew(ft_atoi(ft_substr(argv, 0, len)));
	stack.a = stack.a->next;
	argv = argv + len;
}
argv++;
*/

/* input_stack()
	//t_node	*head;
	//t_node	*node;

	//head = node;
	//stack->a = head;
*/