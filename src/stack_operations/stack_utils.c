/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcel>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:26 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/28 10:41:22 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	ft_new_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

// t_node *ft_new_node(int value, int *sorted_array) {
//     t_node *new_node;
    
//     new_node = (t_node *) malloc(sizeof(t_node));
//     if (!new_node)
//         return (NULL);
//     new_node->value = value;
//     new_node->next = NULL;
//     new_node->index = ft_find_index(value, sorted_array);
//     return new_node;
// }

t_stack *ft_init_stack() {
    t_stack *new_stack;

    new_stack = (t_stack *)malloc(sizeof(t_stack));
    if (new_stack == NULL) 
        return (NULL);
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}


void	ft_initialize_stack_a(t_stack *stack_a, t_list *reverse_input, int *sorted_array)
{
	int	*number;

	while (reverse_input)
	{
		number = reverse_input->content;
		ft_stack_push(stack_a, ft_create_new_node(*number, sorted_array));
		reverse_input = reverse_input->next;
	}
}

void    ft_print_stack(const t_stack *stack) 
{
    if (stack == NULL || stack->top == NULL) 
    {
        ft_printf("Empty stack.\n");
        return;
    }

    t_node *current_node = stack->top;

    ft_printf("Stack contents:\n");
    while (current_node->next != stack->top) 
    {
        ft_printf("Value: %d, Index: %d\n", current_node->value, current_node->index);
        current_node = current_node->next;
    }
    ft_printf("Value: %d, Index: %d\n", current_node->value, current_node->index);
}

