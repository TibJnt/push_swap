/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcel>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:26 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/20 19:06:26 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	ft_new_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

t_node *ft_new_node(int value, int *sorted_array) {
    t_node *new_node;
    
    new_node = (t_node *) malloc(sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->next = NULL;
    new_node->index = ft_find_index(value, sorted_array);
    return new_node;
}

int ft_find_index(int value, int *sorted_array) {
    int i;

    i = 0;
    while (sorted_array[i] != value)
        i++;
    return (i);
}

t_stack *ft_init_stack() {
    t_stack *new_stack;

    new_stack = (t_stack *)malloc(sizeof(t_stack));
    if (new_stack == NULL) 
        return (NULL);
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}