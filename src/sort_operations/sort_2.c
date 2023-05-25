/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:19:39 by tjeunet           #+#    #+#             */
/*   Updated: 2023/05/23 13:59:21 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_already_sort(t_list *list)
{
	int	*number;
	int	*next_number;

	number = list->content;
	list = list->next;
	while (list)
	{
		next_number = (int *)list->content;
		if (*number < *next_number)
			return (0);
		number = next_number;
		list = list->next;
	}
	ft_lstclear(&list, ft_free_null);
	return (1);
}

void	ft_sort_four(t_stack *stack_a)
{	
	t_stack	stack_b;

	ft_new_stack(&stack_b);
	while (stack_a->top->index != 0)
		ft_rotate(stack_a, "ra\n");
	ft_push_node(stack_a, &stack_b, "pb\n");
	ft_sort_three(stack_a);
	ft_push_node(&stack_b, stack_a, "pa\n");
}

void	ft_sort_five(t_stack *stack_a)
{
	t_stack		stack_b;

	ft_new_stack(&stack_b);
	while (stack_a->size > 3)
	{
		if (find_num(stack_a, 0) == 0 || find_num(stack_a, 1) == 0)
			ft_push_node(stack_a, &stack_b, PUSH_B);
		else
			ft_rotate(stack_a, ROTATE_A);
	}
	ft_sort_three(stack_a);
	while (stack_b.size > 0)
		ft_push_node(&stack_b, stack_a, PUSH_A);
	if (stack_a->top->index > stack_a->top->next->index)
		ft_swap(stack_a, SWAP_A);
}

void	ft_sort_big(t_stack *stack_a)
{
	t_stack	stack_b;
	int		size;
	int		max_num;
	int		max_bits;
	int		i;

	ft_new_stack(&stack_b);
	size = stack_a->size;
	max_num = size - 1;
	max_bits = 0;
	while (max_num)
	{
		max_num = max_num >> 1;
		max_bits++;
	}
	i = 0;
	while (i < max_bits)
	{
		ft_sort_digits(stack_a, &stack_b, i);
		while (stack_b.size)
			ft_push_node(&stack_b, stack_a, PUSH_A);
		stack_b.top = NULL;
		i++;
	}
}

void	ft_sort_digits(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	num;
	int	i;
	int	size;

	i = 0;
	size = stack_a->size;
	while (i < size)
	{
		num = stack_a->top->index;
		if ((num >> bit) & 1)
			ft_rotate(stack_a, ROTATE_A);
		else
			ft_push_node(stack_a, stack_b, PUSH_B);
		i++;
	}
}
