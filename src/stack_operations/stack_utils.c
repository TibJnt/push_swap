/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:26 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/29 13:41:03 by tjeunet          ###   ########.fr       */
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
        ft_print_stack(stack_a, "A");
		reverse_input = reverse_input->next;
	}
}

void    ft_print_stack(const t_stack *stack, char *option) 
{
    if (stack == NULL || stack->top == NULL) 
    {
        ft_printf("Empty stack.\n");
        return;
    }

    t_node *current_node = stack->top;

    ft_printf("Stack contents %s :\n", option);
    while (current_node->next != stack->top) 
    {
        ft_printf("Value: %d, Index: %d, Prev: %p, Current: %p, Next: %p\n", current_node->value, current_node->index, current_node->prev, current_node->next);
        current_node = current_node->next;
    }
    ft_printf("Value: %d, Index: %d, Prev: %p, Current: %p, Next: %p\n", current_node->value, current_node->index, current_node->prev, current_node->next);
}

int ft_stack_node_count(t_stack *stack) 
{
    if (stack == NULL || stack->top == NULL) {
        return 0;
    }

    t_node *current_node = stack->top;
    int count = 0;

    do {
        count++;
        current_node = current_node->next;
    } while (current_node != stack->top);

    return count;
}