/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:15:20 by tjeunet           #+#    #+#             */
/*   Updated: 2023/03/23 13:13:08 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(void)
{
	ft_printf("-->Error\n");
	exit(-1);
}

void print_linked_list(const t_list *list)
{
    if (list == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    const t_list *current = list;

    printf("Linked list contents:\n");
    while (current != NULL)
    {
        int value = *((int *)current->content); // Assuming content is of int type
        printf("%d\n", value);
        current = current->next;
    }
}

int main (int argc, char **argv)
{
    t_stack	stack_a;
	t_list	*reverse_input;
	int		*sort;

	ft_new_stack(&stack_a);
	reverse_input = NULL;
	sort = NULL;
	
	ft_parse(argc, argv, &reverse_input, &sort);
	if (ft_is_already_sort(reverse_input))
		return (SUCCESS);
	ft_initialize_stack_a(&stack_a, reverse_input, sort);

	print_linked_list(reverse_input);

	int i = 0;
	ft_printf("sorted array content : \n");
	while (i < stack_a.size)
	{
		ft_printf("%d\n", sort[i]);
		i++;
	}

	ft_lstclear(&reverse_input, ft_free_null);
	ft_printf("stack_size = %d", stack_a.size);
	//ft_print_stack(&stack_a);
	return (SUCCESS);
}