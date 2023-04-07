/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:06:26 by tjeunet           #+#    #+#             */
/*   Updated: 2023/04/07 13:04:08 by tjeunet          ###   ########.fr       */
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
