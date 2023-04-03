/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:15:20 by tjeunet           #+#    #+#             */
/*   Updated: 2023/04/03 12:12:32 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	// ft_printf("Error\n");
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
        int value = *((int *)current->content);
        printf("Value: %d, Current: %p, Next: %p \n", value, current, current->next);
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
	ft_lstclear(&reverse_input, ft_free_null);
	ft_sort(&stack_a);
	free(sort);
	// system("leaks push_swap");
	return (SUCCESS);
}