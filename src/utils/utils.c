/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeunet <tjeunet@student.42barcelona.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 10:47:52 by tjeunet           #+#    #+#             */
/*   Updated: 2023/04/07 13:13:44 by tjeunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_check(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign = -sign;
		i++;
	}
	else if (str[i] == 43)
		i++;
	return (ft_atoi_check_helper(sign, i, str));
}

int	ft_atoi_check_helper(int sign, int i, const char *str)
{
	long long	number;

	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - 48;
		if (sign == 1 && number > INT_MAX)
			ft_error_exit();
		else if (sign == -1 && -(number) < INT_MIN)
			ft_error_exit();
		i++;
	}
	return ((int)(number * sign));
}

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}
