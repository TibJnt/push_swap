/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:26 by tjeunet           #+#    #+#             */
/*   Updated: 2023/05/25 10:00:23 by tjeunet          ###   ########.fr       */
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

t_node	*find_node(t_stack *stack, int index)
{
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	current = stack->top;
	while (current != NULL)
	{
		if (current->index == index)
			return (current);
		current = current->prev;
	}
	return (NULL);
}

int	find_num(t_stack *stack, int num)
{
	t_node	*node;
	int		pos;

	pos = 0;
	node = stack->top;
	while (pos < stack->size)
	{
		if (node->index == num)
			break ;
		node = node->next;
		pos++;
	}
	return (pos);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node	*node;
	int		i;
	int		l;

	i = 0;
	l = 1;
	node = stack->top;
	while (i < stack->size)
	{
		if (node->value > node->next->value)
		{
			l = 0;
			break ;
		}
		node = node->next;
		i++;
	}
	return (l);
}
