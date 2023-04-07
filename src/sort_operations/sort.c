/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:10:22 by tjeunet           #+#    #+#             */
/*   Updated: 2023/04/07 13:33:31 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_to_array(t_list	**list, int **sort)
{
	int		size;
	int		*number;
	int		*array;
	t_list	*tmp;

	size = ft_lstsize(*list);
	array = ft_calloc(size + 1, sizeof(int));
	*sort = array;
	tmp = *list;
	while (tmp)
	{
		number = tmp->content;
		*array = *number;
		++array;
		tmp = tmp->next;
	}
}

void	ft_add_number_sorting(t_list *new, t_list **list)
{
	t_list	*tmp;
	t_list	*previous;

	tmp = *list;
	previous = *list;
	while (tmp)
	{
		if (*(int *)(new->content) == *(int *)(tmp->content))
			ft_error_exit();
		if (*(int *)(new->content) < *(int *)(tmp->content))
		{
			new->next = tmp;
			if (tmp == *list)
				*list = new;
			else
				previous->next = new;
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
	ft_lstadd_back(list, new);
}

void	ft_sort(t_stack *stack_a)
{
	if (stack_a->size == 2)
		ft_swap(stack_a, SWAP_A);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else if (stack_a->size == 4)
		ft_sort_four(stack_a);
	else if (stack_a->size == 5)
		ft_sort_five(stack_a);
	else
		ft_sort_big(stack_a);
	ft_free_stack(stack_a);
}

void	ft_sort_three(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack_a == NULL)
		return ;
	first = stack_a->top;
	second = first->next;
	third = second->next;
	help_three(stack_a, first, second, third);
	if (first->index < second->index && second->index > third->index
		&& first->index < third->index)
	{
		ft_swap(stack_a, "sa\n");
		ft_rotate(stack_a, "ra\n");
	}
	else if (first->index < second->index && second->index > third->index
		&& first->index > third->index)
		ft_rev_rotate(stack_a, "rra\n");
}

void	help_three(t_stack *stack_a, t_node *first, t_node *sec, t_node *third)
{
	if (first->index > sec->index && sec->index < third->index
		&& first->index < third->index)
		ft_swap(stack_a, "sa\n");
	else if (first->index > sec->index && sec->index > third->index
		&& first->index > third->index)
	{
		ft_swap(stack_a, "sa\n");
		ft_rev_rotate(stack_a, "rra\n");
	}
	else if (first->index > sec->index && sec->index < third->index
		&& first->index > third->index)
		ft_rotate(stack_a, "ra\n");
}
