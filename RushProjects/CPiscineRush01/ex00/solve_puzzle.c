/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz <aschulz@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:25:22 by aschulz           #+#    #+#             */
/*   Updated: 2024/09/09 10:56:55 by kbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puzzle.h"

int	is_safe_to_place(int **grid, int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == num)
			return (0);
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve_next_cell(int **grid, int *constraints, int row, int col)
{
	if (col == SIZE)
		return (solve_puzzle(grid, constraints, row + 1, 0));
	return (0);
}

int	solve_puzzle(int **grid, int *constraints, int row, int col)
{
	int	i;

	if (row == SIZE)
		return (check_visibility(grid, constraints));
	if (solve_next_cell(grid, constraints, row, col))
		return (1);
	i = 1;
	while (i <= SIZE)
	{
		if (is_safe_to_place(grid, row, col, i))
		{
			grid[row][col] = i;
			if (solve_puzzle(grid, constraints, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		i++;
	}
	return (0);
}
