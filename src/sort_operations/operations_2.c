/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:52:33 by tjeunet           #+#    #+#             */
/*   Updated: 2023/04/07 11:56:44 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack, char *option)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	stack->top = second;
	ft_printf("%s", option);
}

void	ft_rev_rotate(t_stack *stack, char *option)
{
	t_node	*last;

	if (stack == NULL || stack->size <= 2)
		return ;
	last = stack->top->prev;
	stack->top = last;
	ft_printf("%s", option);
}
