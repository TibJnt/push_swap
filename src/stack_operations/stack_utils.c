/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:26 by tjeunet           #+#    #+#             */
/*   Updated: 2023/05/10 12:52:27 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	ft_new_stack(t_stack *stack)
{
	stack->size = 0;
	stack->top = NULL;
}

void	ft_init_stack_a(t_stack *stack_a, t_list *rev_input, int *sort_array)
{
	int	*number;

	while (rev_input)
	{
		number = rev_input->content;
		ft_stack_push(stack_a, ft_create_new_node(*number, sort_array));
		rev_input = rev_input->next;
	}
}

t_node *find_node(t_stack *stack, int index) {

    if (stack == NULL || stack->top == NULL) {
        return NULL; // return NULL if the stack is empty
    }

    t_node *current = stack->top;

    while (current != NULL) {
        if (current->index == index) {
            return current; // return the node if the index matches
        }
        current = current->prev; // go to the previous node
    }

    return NULL; // return NULL if the node was not found
}

int	find_num(t_stack *stack, int num)
{
	t_node	*node;
	int		pos;

	pos = 0;
	node = stack->top;
	while ( pos < stack->size)
	{
		if (node->index == num)
			break ;
		node = node->next;
		pos++;
	}
	return (pos);
}
