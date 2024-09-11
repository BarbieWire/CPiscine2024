/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazmi <skazmi@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:19:35 by skazmi            #+#    #+#             */
/*   Updated: 2024/09/08 21:00:29 by aschulz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLE_H
# define PUZZLE_H

# include <stdlib.h>

# define NUMBER_OF_CONSTRAINTS 16
# define SIZE 4

void	print_grid(int **grid);

int		*parse_input(char *input);
int		is_safe_to_place(int **grid, int row, int col, int num);
int		check_direction(int *line, int expected, int reverse);
int		check_visibility(int **grid, int *constraints);
int		solve_puzzle(int **grid, int *constraints, int row, int col);

#endif /* PUZZLE_H */
