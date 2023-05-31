/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:15:20 by tjeunet           #+#    #+#             */
/*   Updated: 2023/05/31 10:23:18 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_stack		stack_a;
// 	t_list		*reverse_input;
// 	int			*sort;

// 	ft_new_stack(&stack_a);
// 	reverse_input = NULL;
// 	sort = NULL;
// 	ft_parse(argc, argv, &reverse_input, &sort);
// 	if (ft_is_already_sort(reverse_input))
// 	{
// 		if (reverse_input)
// 		{
// 			if (sort)
// 				free(sort);
// 			ft_lstclear(&reverse_input, ft_free_null);
// 			return (SUCCESS);
// 		}
// 	}
// 	ft_init_stack_a(&stack_a, reverse_input, sort);
// 	if (sort)
// 		free(sort);
// 	ft_lstclear(&reverse_input, ft_free_null);
// 	ft_sort(&stack_a);
// 	return (SUCCESS);
// }

static int	cleanup_success(t_list *reverse_input, int *sort)
{
	if (sort)
		free(sort);
	ft_lstclear(&reverse_input, ft_free_null);
	return (SUCCESS);
}

static int	cleanup_sort(t_stack *stack_a, t_list *reverse_input, int *sort)
{
	if (sort)
		free(sort);
	ft_lstclear(&reverse_input, ft_free_null);
	ft_sort(stack_a);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_list	*reverse_input;
	int		*sort;

	ft_new_stack(&stack_a);
	reverse_input = NULL;
	sort = NULL;
	ft_parse(argc, argv, &reverse_input, &sort);
	if (ft_is_already_sort(reverse_input))
		return (cleanup_success(reverse_input, sort));
	ft_init_stack_a(&stack_a, reverse_input, sort);
	return (cleanup_sort(&stack_a, reverse_input, sort));
}
