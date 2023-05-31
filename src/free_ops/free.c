/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:50:28 by tjeunet           #+#    #+#             */
/*   Updated: 2023/05/31 10:23:42 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_null(void *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
}

void	ft_free_char_2pointer(char **pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		return ;
	while (pointer[i])
		ft_free_null(pointer[i++]);
	ft_free_null(pointer);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*current_node;
	t_node	*next_node;
	int		size;
	int		i;

	i = 0;
	if (stack == NULL)
		return ;
	size = stack->size;
	current_node = stack->top;
	next_node = stack->top;
	while (i < size)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
		i++;
	}
}

void	ft_free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp);
	}
	*lst = NULL;
}
