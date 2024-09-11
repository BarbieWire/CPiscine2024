/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz <aschulz@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:00:53 by aschulz           #+#    #+#             */
/*   Updated: 2024/09/08 16:58:11 by aschulz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*parse_input(char *input);
void	print_error(void);

int	initialize_constraints(int argc, char **argv, int **constraints)
{
	if (argc != 2)
	{
		print_error();
		return (0);
	}
	*constraints = parse_input(argv[1]);
	if (!*constraints)
	{
		print_error();
		return (0);
	}
	return (1);
}
