/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_space_solution.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <rafarauj@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:59:21 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/20 19:56:36 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_counting_zeros(int array_solution_space[4][4][4],
						int found_solution[4][4], int x, int y)
{
	int	z;
	int	c;

	z = 0;
	c = 0;
	while (z <= 3)
	{
		if (array_solution_space[x][y][z] == 0)
			c++;
		else
			found_solution[x][y] = array_solution_space[x][y][z];
		z++;
	}
	return (c);
}

/*
Returns 1 if the heigth in (pos_x, pos_y) appears already in the same
row or column.
*/
int	ft_is_repeated_height(int sol[4][4], int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	found;

	found = 0;
	x = 0;
	y = 0;
	while (!found && x < 4)
	{
		while (!found && y < 4)
		{
			if ((pos_x == x || pos_y == y) && !(pos_x == x && pos_y == y))
				found = sol[x][y] == sol[pos_x][pos_y];
			y++;
		}
		x++;
	}
	return (found);
}

/*
Returns 1 a height appears more than once in the same row or column;
0 otherwise
*/
int	ft_no_repeated_height(int sol[4][4])
{
	int	x;
	int	y;
	int	found;

	found = 0;
	x = 0;
	y = 0;
	while (!found && x < 4)
	{
		while (!found && y < 4)
		{
			found = ft_is_repeated_height(sol, x, y);
			y++;
		}
		x++;
	}
	return (found);
}

/*
	checks if array_solution_space cotains one and only one candidate solution
	parameters:
	array_solution_space contains possible solution
	found_solution recieves final or possibe solution if there is one
	returns:
	returns 0 if there is no solution
	returns 1 if solution is possible
*/
int	ft_is_solution(int array_solution_space[4][4][4], int found_solution[4][4])
{
	int	x;
	int	y;
	int	c;

	x = 0;
	c = 3;
	while (x <= 3 && c == 3)
	{
		y = 0;
		while (y <= 3 && c == 3)
		{
			c = ft_counting_zeros (array_solution_space, found_solution, x, y);
			y++;
		}
		x++;
	}
	if (c != 3)
		return (0);
	else
	{
		return (ft_no_repeated_height(found_solution));
	}
}
/*
	Filing solution space arrays
    parameter:
    three-dimensional array

 */

void	ft_fill_space_solution(int array_solution_space[4][4][4])
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (x <= 3)
	{
		y = 0;
		while (y <= 3)
		{
			z = 0;
			while (z <= 3)
			{
				array_solution_space[x][y][z] = z + 1;
				z++;
			}
			y++;
		}
		x++;
	}
}

/*
  Copies src in dst
*/
void	ft_cp_sol_spc(int src[4][4][4], int dst[4][4][4])
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (x <= 3)
	{
		y = 0;
		while (y <= 3)
		{
			z = 0;
			while (z <= 3)
			{
				dst[x][y][z] = src[x][y][z];
				z++;
			}
			y++;
		}
		x++;
	}
}

void	ft_clear_selected_xy(int pos_x, int pos_y, int pos_z,
		int array_solution_space[4][4][4]);

void	ft_clear(int pos_x, int pos_y, int pos_z,
		int array_solution_space[4][4][4])
{
	int	found_solution[4][4];
	int	z;

	if (array_solution_space[pos_x][pos_y][pos_z] != 0)
	{
		array_solution_space[pos_x][pos_y][pos_z] = 0;

		if (ft_counting_zeros(array_solution_space, 
				found_solution, pos_x, pos_y) == 3)
		{
			z = 0;
			while (z < 4)
			{
				if (array_solution_space[pos_x][pos_y][z] != 0)
				{
					ft_clear_selected_xy(pos_x, pos_y, z, array_solution_space);
					z = 5;
				}
				z++;
			}
		}
	}
}

/*
 Given a number N in (pos_x, pos_y, pos_z), updates the solution
space replacing N by 0 in cells along axes X and Y, except in
(pos_x, pos_y). 
*/
void	ft_clear_selected_xy(int pos_x, int pos_y, int pos_z,
	int array_solution_space[4][4][4])
{
	int	x;
	int	y;
	int	z;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			z = 0;
			while (z < 4)
			{
				if (x == pos_x && y == pos_y)
				{
					if (z != pos_z)
					{
						ft_clear(x, y, z, array_solution_space);
					}
				}
				else
					if ((x == pos_x || y == pos_y)
						&& array_solution_space[x][y][z] ==
							array_solution_space[pos_x][pos_y][pos_z])
					{
						ft_clear(x, y, z, array_solution_space);
					}
				z++;
			}
			y++;
		}
		x++;
	}
}

/*
  Updates the solution space by "selecting" the number in (pos_x, pos_y,
pos_z).
  Returns:
	0 when the number in (pos_x, pos_y pos_z) is 0;
	1 otherwise.
*/
int	ft_apply_selection(
	int pos_x, int pos_y, int pos_z,
	int array_solution_space[4][4][4])
{
	int	result;

	result = 0;
	if (array_solution_space[pos_x][pos_y][pos_z] != 0)
	{
		result = 1;
		ft_clear_selected_xy(pos_x, pos_y, pos_z, array_solution_space);
	}
	return (result);
}
