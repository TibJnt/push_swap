/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:26 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/30 12:16:06 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	ft_new_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
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
        ft_printf("Value: %d, Index: %d, Bin: %s, Prev: %p, Current: %p, Next: %p\n", current_node->value, current_node->index, int_to_binary(current_node->index), current_node->prev, current_node, current_node->next);
        current_node = current_node->next;
    }
        ft_printf("Value: %d, Index: %d, Bin: %s, Prev: %p, Current: %p, Next: %p\n", current_node->value, current_node->index, int_to_binary(current_node->index), current_node->prev, current_node, current_node->next);
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

char *int_to_binary(int num) {
    char temp[33]; // Temporary buffer for 32 bits + 1 null terminator
    unsigned int mask = 1 << 31;
    int pos = 0;
    int leading_zero = 1;

    for (int i = 0; i < 32; i++) {
        if ((num & mask) != 0) {
            leading_zero = 0;
        }
        if (!leading_zero) {
            temp[pos++] = (num & mask) ? '1' : '0';
        }
        mask >>= 1;
    }

    if (pos == 0) { // Handle the case when num is 0
        temp[pos++] = '0';
    }
    temp[pos] = '\0';

    char *binary = malloc(pos + 1); // Allocate memory for the significant digits
    if (binary == NULL) {
        return NULL;
    }

    for (int i = 0; i <= pos; i++) {
        binary[i] = temp[i];
    }

    return binary;
}