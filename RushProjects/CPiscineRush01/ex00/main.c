/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz <aschulz@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:55:01 by aschulz           #+#    #+#             */
/*   Updated: 2024/09/09 10:56:58 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		initialize_constraints(int argc, char **argv, int **constraints);
int		**allocate_grid(void);
void	free_grid(int **grid);
int		solve_puzzle(int **grid, int *constraints, int row, int col);
void	print_grid(int **grid);
void	print_error(void);

int	main(int argc, char **argv)
{
	int	*constraints;
	int	**grid;

	if (!initialize_constraints(argc, argv, &constraints))
		return (1);
	grid = allocate_grid();
	if (!grid)
	{
		free(constraints);
		return (1);
	}
	if (solve_puzzle(grid, constraints, 0, 0))
		print_grid(grid);
	else
		print_error();
	free_grid(grid);
	free(constraints);
	return (0);
}
