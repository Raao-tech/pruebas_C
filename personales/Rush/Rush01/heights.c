/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heights.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <rafarauj@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 11:54:32 by lalgarra          #+#    #+#             */
/*   Updated: 2025/07/20 19:54:05 by lalgarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  Given a max_height seen up to now, checks the heigt in
(pos_x, pos_y). If this is a new maximum return 1 and updates max_heigth;
otherwise, returns 0.
*/
int	ft_to_add_seen_heights(
		int *max_height,
		int pos_x, int pos_y,
		int potential_solution[4][4])
{
	int	res;

	res = 0;
	if (potential_solution[pos_x][pos_y] > *max_height)
	{
		res = 1;
		*max_height = potential_solution[pos_x][pos_y];
	}
	return (res);
}

int	ft_count_seen_heights_dirup(
		int potential_solution[4][4],
		int nav_x, int idx)
{
	int	i2;
	int	max_height;
	int	count;

	i2 = 0;
	while (i2 < 4)
	{
		if (nav_x)
			count = count + ft_to_add_seen_heights(&max_height, i2, idx,
					potential_solution);
		else
			count = count + ft_to_add_seen_heights(&max_height, idx, i2,
					potential_solution);
		i2++;
	}
	return (count);
}

int	ft_count_seen_heights_dirdown(
		int potential_solution[4][4],
		int nav_x, int idx)
{
	int	i2;
	int	max_height;
	int	count;

	i2 = 3;
	while (i2 >= 0)
	{
		if (nav_x)
			count = count + ft_to_add_seen_heights(&max_height, i2, idx,
					potential_solution);
		else
			count = count + ft_to_add_seen_heights(&max_height, idx, i2,
					potential_solution);
		i2--;
	}
	return (count);
}

/*
  Computes the number that goes in a positions of the UpDownLeftWright
 array (input conditions).
Parameters:
	potential_solution: array of heights;
	nav_x: must have 1 if we must traverse an array through the X dimension;
		0 to traverse over the Y dimension;
	dir_up: must have 1 if we must traverse from index 0 to 3; 0 to
		traverse from 3 down to 0.
	idx: value tu keep in the "fixed" dimension while traversing.
*/
int	ft_compute_udlr_value(
		int potential_solution[4][4],
		int nav_x, int dir_up,
		int idx)
{
	int	max_height;
	int	count;

	max_height = 0;
	count = 0;
	if (dir_up)
		count = ft_count_seen_heights_dirup(potential_solution, nav_x, idx);
	else
		count = ft_count_seen_heights_dirdown(potential_solution, nav_x, idx);
	return (count);
}
