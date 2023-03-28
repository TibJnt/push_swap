/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcel>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:10:22 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/28 10:22:56 by tjeunet          ###   ########.fr       */
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


void ft_sort(t_stack *stack_a)
{
	if (stack_a->size == 2)
		ft_swap(stack_a, SWAP_A);
	else if (stack_a->size == 3)
		ft_sort_three(stack_a);
	else
		ft_sort_big(stack_a);
}

void ft_sort_three(t_stack *stack_a) {
    if (stack_a == NULL || stack_a->size != 3) {
        return;
    }

    t_node *first = stack_a->top;
    t_node *second = first->next;
    t_node *third = second->next;

    if (first->index > second->index && second->index < third->index && first->index < third->index) {
        ft_swap(stack_a, "sa");
    } else if (first->index > second->index && second->index > third->index && first->index > third->index) {
        ft_swap(stack_a, "sa");
        ft_rev_rotate(stack_a, "rra");
    } else if (first->index > second->index && second->index < third->index && first->index > third->index) {
        ft_rotate(stack_a, "ra");
    } else if (first->index < second->index && second->index > third->index && first->index < third->index) {
        ft_swap(stack_a, "sa");
        ft_rotate(stack_a, "ra");
    } else if (first->index < second->index && second->index > third->index && first->index > third->index) {
        ft_rev_rotate(stack_a, "rra");
    }
}


void 	ft_sort_big(t_stack *stack_a)
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
		while (stack_b->size)
			ft_push_node(stack_b, stack_a, PUSH_A);
		i++;
	}	
}

void	ft_sort_digits(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	num;
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		num = stack_a->top->index;
		if ((num >> bit) & 1)
			ft_rotate(stack_a, ROTATE_A);
		else
			ft_push_node(stack_a, stack_b, PUSH_B);
		i++;
	}
}