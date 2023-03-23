/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:10:22 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/23 16:10:22 by tjeunet          ###   ########.fr       */
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


