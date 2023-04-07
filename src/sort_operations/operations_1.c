/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:06:11 by tjeunet           #+#    #+#             */
/*   Updated: 2023/04/07 11:55:57 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_op(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp_index;
	int		temp_value;

	if (stack == NULL || stack->size <= 2)
		return ;
	first = stack->top;
	second = first->next;
	temp_index = first->index;
	temp_value = first->value;
	first->index = second->index;
	first->value = second->value;
	second->index = temp_index;
	second->value = temp_value;
}

void	ft_swap(t_stack *stack, char *option)
{
	ft_swap_op(stack);
	ft_printf("%s", option);
}

void	ft_double_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_op(stack_a);
	ft_swap_op(stack_b);
	ft_printf("%s", SWAP_DOUBLE);
}

void	ft_push_node(t_stack *src, t_stack *dest, char *option)
{
	t_node	*node;

	node = ft_pop(src);
	if (node == NULL)
		return ;
	ft_stack_push(dest, node);
	ft_printf("%s", option);
}

t_node	*ft_pop(t_stack *stack)
{
	t_node	*last;
	t_node	*node;

	node = stack->top;
	if (!node)
		return (NULL);
	stack->top = node->next;
	last = node->prev;
	ft_connect(last, stack->top);
	node->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}
