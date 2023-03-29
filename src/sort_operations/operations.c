/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:06:11 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/29 12:54:46 by tjeunet          ###   ########.fr       */
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
	ft_printf("%s\n", option);
}

void	ft_double_swap(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_op(stack_a);
	ft_swap_op(stack_b);
	ft_printf("%s\n", SWAP_DOUBLE);
}

void ft_rotate(t_stack *stack, char *option) {
    if (stack == NULL || stack->size < 2) {
		return;
    }
	
	t_node *first = stack->top;

    t_node *second = first->next;

	stack->top = second;
	
	ft_printf("%s\n", option);
}

void ft_rev_rotate(t_stack *stack, char *option) {
	if (stack == NULL || stack->size <= 2) {
		return;
	}

	t_node *last = stack->top->prev;

	stack->top = last;

	ft_printf("%s\n", option);
}

// t_node *ft_pop(t_stack *stack)
// {
//     t_node *top_node;

//     // If the stack is empty, return NULL.
//     if (stack == NULL || stack->top == NULL)
//     {
//         return NULL;
//     }

//     // Get the top element of the stack.
//     top_node = stack->top;

//     // Update the stack's top to point to the next element.
//     stack->top = top_node->next;

//     // If the new top element is not NULL, update its prev to point to the last element.
//     if (stack->top != NULL)
//     {
//         stack->top->prev = top_node->prev;
//     }

//     // If the last element is not NULL, update its next to point to the new top element.
//     if (top_node->prev != NULL)
//     {
//         top_node->prev->next = stack->top;
//     }

//     // Disconnect the popped node from the stack.
//     top_node->next = NULL;
//     top_node->prev = NULL;

// 	// Update the stack's size.
// 	stack->size--;

	

//     // Return the popped node.
//     return top_node;
// }


void ft_push_node(t_stack *src, t_stack *dest, char *option)
{
	t_node *node;

	// Pop the top element from the source stack.
	node = ft_pop(src);

	// If the source stack is empty, return.
	if (node == NULL)
	{
		ft_printf("Node is null in POP function\n");
		return;
	}
	ft_printf("This node was popped / value: %d,  index: %d\n", node->value, node->index);

	// Push the popped element to the destination stack.
	ft_stack_push(dest, node);

	// Print the operation.
	ft_printf("%s\n", option);
}







t_node *ft_pop(t_stack *stack)
{
    t_node *top_node;

    if (stack == NULL || stack->top == NULL)
    {
        return NULL;
    }

    top_node = stack->top;
    stack->top = top_node->next;

    if (stack->top != NULL)
    {
        stack->top->prev = top_node->prev;
    }

    if (top_node->prev != NULL)
    {
        top_node->prev->next = stack->top;
    }

    top_node->next = NULL;
    top_node->prev = NULL;
    stack->size--;

    return top_node;
}



