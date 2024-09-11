/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbondare <kbondare@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:38:42 by kbondare          #+#    #+#             */
/*   Updated: 2024/09/09 15:44:05 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	determine_sign(char **str)
{
	int	sign;
	int	negative_sign_amount;

	sign = 1;
	negative_sign_amount = 0;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
		{
			negative_sign_amount += 1;
		}
		(*str)++;
	}
	if (negative_sign_amount % 2 != 0)
		sign = -1;
	return (sign);
}

void	trim_spaces(char **str)
{
	while (**str == ' ')
	{
		(*str)++;
	}
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	trim_spaces(&str);
	sign = determine_sign(&str);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (result > (INT_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
