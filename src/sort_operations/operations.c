/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:06:11 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/24 14:31:47 by tjeunet          ###   ########.fr       */
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

void ft_rotate(t_stack *stack, char *option) {
    if (stack == NULL || stack->size <= 2) {
        return;
    }

	t_node *first = stack->top;

    t_node *second = first->next;


	stack->top = second;
	
	ft_printf("%s", option);

}

void ft_rev_rotate(t_stack *stack, char *option) {
	if (stack == NULL || stack->size <= 2) {
		return;
	}

	t_node *last = stack->top->prev;

	stack->top = last;

	ft_printf("%s", option);
}