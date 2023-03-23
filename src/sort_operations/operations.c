/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:06:11 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/23 16:21:39 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_op(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	first = stack->top;
	if (!first)
		return ;
	second = first->next;
	third = second->next;
	last = first->prev;
	if (first == second)
		return ;
	if (third != first)
	{
		ft_connect(last, second);
		ft_connect(second, first);
		ft_connect(first, third);
	}
	stack->top = second;
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