/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:47:12 by tjeunet           #+#    #+#             */
/*   Updated: 2023/04/07 12:56:31 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_new_node(int value, int *sorted_array)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = ft_find_index(value, sorted_array);
	return (new_node);
}

int	ft_find_index(int value, int *sorted_array)
{
	int	i;

	i = 0;
	while (sorted_array[i] != value)
		i++;
	return (i);
}

void	ft_stack_push(t_stack *stack, t_node *node)
{
	t_node	*top;
	t_node	*last;

	if (!stack || !node)
		return ;
	top = stack->top;
	if (!top)
	{
		ft_connect(node, node);
		stack->top = node;
	}
	else
	{
		last = top->prev;
		ft_connect(last, node);
		ft_connect(node, top);
	}
	stack->top = node;
	stack->size++;
}

void	ft_connect(t_node *first, t_node *second)
{
	if (!first)
		return ;
	if (!second)
		return ;
	first->next = second;
	second->prev = first;
}

t_node	*ft_find_max_node(t_stack *stack)
{
	t_node	*current;
	t_node	*max_node;

	if (stack == NULL || stack->size == 0)
		return (NULL);
	current = stack->top;
	max_node = current;
	while (current != NULL)
	{
		if (current->value > max_node->value)
			max_node = current;
		current = current->next;
	}
	return (max_node);
}
