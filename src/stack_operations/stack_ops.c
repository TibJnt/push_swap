/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:47:12 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/21 15:52:19 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *create_new_node(int value, int *sorted_array) 
{
    t_node *new_node;
    
    new_node = (t_node *) malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    new_node->index = ft_find_index(value, sorted_array);
    return new_node;
}

int ft_find_index(int value, int *sorted_array) 
{
    int i;

    i = 0;
    while (sorted_array[i] != value)
        i++;
    return (i);
}

void swap(t_stack *stack) 
{
    t_node *first_node;
    t_node *second_node;
    int     temp;

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL) 
        return ;
    first_node = stack->top;
    second_node = stack->top->next;
    temp = first_node->value;
    first_node->value = second_node->value;
    second_node->value = temp;
}

void push(t_stack *src, t_stack *dest) 
{
    t_node *src_top_node;

    if (src == NULL || dest == NULL || src->top == NULL) 
        return ;
    src_top_node = src->top;
    src->top = src->top->next;
    src->size--;
    src_top_node->next = dest->top;
    dest->top = src_top_node;
    dest->size++;
}

void rotate(t_stack *stack) 
{
    t_node *first_node;
    t_node *second_node;
    t_node *current_node;

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return ;
    first_node = stack->top;
    second_node = stack->top->next;
    stack->top = second_node;
    current_node = second_node;
    while (current_node->next != NULL)
        current_node = current_node->next;
    current_node->next = first_node;
    first_node->next = NULL;
}

void reverse_rotate(t_stack *stack) 
{
    t_node *last_node;
    t_node *second_last_node;

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
        return ;
    last_node = stack->top;
    second_last_node = NULL;
    while (last_node->next != NULL) 
    {
        second_last_node = last_node;
        last_node = last_node->next;
    }
    second_last_node->next = NULL;
    last_node->next = stack->top;
    stack->top = last_node;
}

void	ft_stack_push(t_stack *stack, t_node *node)
{
	t_node	*top;
	t_node	*last;

	top = stack->top;
	if (!top)
		ft_connect(node, node);
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
	first->next = second;
	second->prev = first;
}

