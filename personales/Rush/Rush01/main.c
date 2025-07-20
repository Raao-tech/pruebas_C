/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <rafarauj@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 03:17:01 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/20 19:45:05 by lalgarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "common.h"

void	ft_populate_udlr(int solution[4][4], int my_udlr[4][4])
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 3)
	{
		while (y < 3)
		{
			if (x == 0)
				my_udlr[x][y] = 
					ft_compute_udlr_value(solution, 0, 1, y);
			if (x == 1)
				my_udlr[x][y] = 
					ft_compute_udlr_value(solution, 0, 0, y);
			if (x == 2)
				my_udlr[x][y] = 
					ft_compute_udlr_value(solution, 1, 1, x);
			if (x == 3)
				my_udlr[x][y] = 
					ft_compute_udlr_value(solution, 1, 0, x);
			y++;
		}
		x++;
	}
}
/*
  Computes numbers in UDLR for 'solution', and checks if they are the same
that those in 'array_udlr'.
Return 1 if they are the same numbers; 0 otherwise.
*/
int	ft_is_legal_solution(int solution[4][4], int array_udlr[4][4])
{
	int	x;
	int	y;
	int my_udlr[4][4];
	int is_legal;

	is_legal = 1;
	ft_populate_udlr(solution, my_udlr);
	x = 0;
	y = 0;
	while (is_legal && x < 3)
	{
		while (is_legal && y < 3)
		{
			is_legal = my_udlr[x][y] == array_udlr[x][y];
			y++;
		}
		x++;
	}

	return (is_legal);
}

/*
  Parses array_solution_space looking for an (x, y) element where at least
2 possibilities are still available.
Parameters:
	array_solution_space,
	x, y: indexes; the get updated by this function.
Returs: the count of zeroes found in (x, y)
*/
int ft_find_candidate_cell(int array_solution_space[4][4][4], int *x, int *y)
{
	int c;
	int	found;
	int solution[4][4];

	*x = 0;
	c = 0;
	found = 0;
	while (*x < 4 && !found)
	{
		*y = 0;
		while (*y < 4 && !found)
		{
			c = ft_counting_zeros(array_solution_space, solution, *x, *y);
			found = c < 3;
			if (!found)
				(*y)++;
		}
		if (!found)
			(*x)++;
	}
	return (c);
}

/*
Trabaja sobre el espacio de soluciones recibido, buscando una potencial
solución. Cuando la encuentra, verifica si se corresponde con los datos de
entrada.
En caso afirmativo, habrá encontrado una solución, y devolverá 1;
en otro caso, devolverá 0.
x, y, z dicen cuál fue la última alternativa probada
*/
int	ft_find_solution(
	int array_solution_space[4][4][4],
	int array_udlr[4][4],
	int x, int y, int z,
	int solution[4][4])
{
	int result;
	int	sp_copy[4][4][4];
	int	alt_x;
	int alt_y;
	int	alt_z;

	result = 0;
	if (x <= 3 && y <= 3 && z <= 3)
	{
			ft_cp_sol_spc(array_solution_space, sp_copy);
			ft_apply_selection(x, y, z, sp_copy);

			if (ft_is_solution(sp_copy, solution)
				&& ft_is_legal_solution(solution, array_udlr))
				result = 1;
			else
			{
				if (ft_find_candidate_cell(sp_copy, &alt_x, &alt_y) < 3)
				{
					alt_z = 0;
					while (sp_copy[alt_x][alt_y][alt_z] == 0 && alt_z <= 3)
						alt_z++;
					if (alt_z <= 3)
						result = ft_find_solution(sp_copy, array_udlr,
							alt_x, alt_y, alt_z, solution);
				}
				if (!result)
				{
					z++;
					while (array_solution_space[x][y][z] == 0 && z < 4)
						z++;
					if (z <= 3)
						result = ft_find_solution(array_solution_space, array_udlr, x, y, z, solution);
				}
			}

	}
	return (result);
}


int	main(int argc,char *argv[])
{
	int	error;
	int	array_udlr[4][4];
	int array_solution_space[4][4][4];
	int	is_sol;
	int	solution[4][4];

	error = 0;
	if (argc == 2 && ft_arg_is_valid(argv[1]))
	{
		if (ft_input_cleaner(argv[1]))
		{	
			populate_udlr(array_udlr,argv[1]);
			ft_fill_space_solution(array_solution_space);
			is_sol = ft_find_solution(array_solution_space,
				array_udlr, 0, 0, 0, solution);
			if (is_sol)
				ft_put_ar(solution);
			else
				error = 1;
		}
		else
			error = 1;
	}
	else
		error = 1;
	if (error)
		write (2,"Error\n", 6);
	return (error);
}
