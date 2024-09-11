/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz <aschulz@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:47:48 by aschulz           #+#    #+#             */
/*   Updated: 2024/09/09 10:52:50 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

int	*parse_input(char *input)
{
	int	*result;
	int	i;

	result = malloc(sizeof(int) * NUMBER_OF_CONSTRAINTS);
	if (!result)
		return (NULL);
	i = 0;
	while (*input != '\0')
	{
		if (*input >= '1' && *input <= '4')
		{
			result[i] = *input - '0';
			i++;
		}
		input++;
	}
	if (i != NUMBER_OF_CONSTRAINTS)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
