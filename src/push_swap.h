/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:35:22 by tjeunet           #+#    #+#             */
/*   Updated: 2023/05/31 12:11:06 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include"../Libft/libft.h"

# define SUCCESS 0

# define SWAP_A			"sa\n"
# define SWAP_B			"sb\n"
# define SWAP_DOUBLE	"ss\n"
# define PUSH_A			"pa\n"
# define PUSH_B			"pb\n"
# define ROTATE_A		"ra\n"
# define ROTATE_B		"rb\n"
# define ROTATE			"rr\n"
# define REV_ROTATE_A	"rra\n"
# define REV_ROTATE_B	"rrb\n"
# define REV_ROTATE		"rrr\n"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void	ft_push(t_stack *stack_a, t_stack *stack_b, char *option);
void	ft_rev_rotate(t_stack *stack, char *option);
void	ft_double_rev_rotate(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate(t_stack *stack, char *option);
void	ft_double_rotate(t_stack *stack_a, t_stack *stack_b);
void	ft_swap(t_stack *stack, char *option);
void	ft_double_swap(t_stack *stack_a, t_stack *stack_b);
t_node	*ft_pop(t_stack *stack);
void	ft_push_node(t_stack *src, t_stack *dest, char *option);

// ========================== PARSE =================================== //

void	ft_parse(int argc, char **argv, t_list **reverse_input, int **sort);
void	ft_list_to_array(t_list	**list, int **sort);
void	ft_add_number_sorting(t_list *new, t_list **list);
int		check_int_overflow(char *str);

// ========================== SORT ===================================== //

void	ft_sort(t_stack *stack_a);
int		ft_is_already_sort(t_list *list);
void	swap(t_stack *stack);
void	push(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	ft_swap(t_stack *stack, char *option);
void	ft_sort_three(t_stack *stack_a);
void	help_three(t_stack *stack_a, t_node *first, t_node *sec, t_node *third);
void	ft_sort_big(t_stack *stack_a);
void	ft_sort_digits(t_stack *stack_a, t_stack *stack_b, int bit);
void	ft_sort_five(t_stack *stack_a);
void	ft_sort_four(t_stack *stack_a);

// ========================== STACK ===================================== //

void	ft_connect(t_node *first, t_node *second);
void	ft_new_stack(t_stack *stack);
t_node	*ft_stack_pop(t_stack *stack);
t_node	*ft_create_new_node(int value, int *sorted_array);
void	ft_stack_push(t_stack *stack, t_node *node);
void	ft_init_stack_a(t_stack *stack_a, t_list *rev_input, int *sort_array);
int		ft_find_index(int value, int *sorted_array);
void	ft_print_stack(const t_stack *stack, char *option);
int		ft_stack_node_count(t_stack *stack);
char	*int_to_binary(int num);
t_node	*ft_find_max_node(t_stack *stack);
t_node	*find_node(t_stack *stack, int index);
int		find_num(t_stack *stack, int num);

//free.c
void	ft_free_list(t_list **lst);
void	ft_free_char_2pointer(char **pointer);
void	ft_free_null(void *pointer);
void	ft_free_stack(t_stack *stack);

//utils.c
int		ft_atoi_check(const char *str);
int		ft_atoi_check_helper(int sign, int i, const char *str);
void	ft_error_exit(void);
void	stack_printf(t_stack	*sactk);

#endif
