/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrelor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:08:30 by andrelor          #+#    #+#             */
/*   Updated: 2025/07/19 17:46:41 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
  Validates the argument with which the program was invoked.
Parameter:
	str: pointer to the argument string.
Returns:
	0 if the argument is not valid
	1 otherwise
*/
int	ft_arg_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || (str[i] <= '4' && str[i] >= '1'))
			i++;
		else
			return (0);
	}
	return (1);
}

/*
    To do: validate if input is valid to operate

    Parameter: string made of numbers (from 1-4) and spaces separated 
	consecutively
    
    Returns:
	0 if the argument is not valid
	1 otherwise
*/

int	ft_input_cleaner(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (result && str[i] != '\0')
	{
		if (!((i % 2 > 0 && str[i] == ' ')
				|| (i % 2 == 0 && str[i] != ' ')))
			result = 0;
		i++;
	}
	if (i != 2 * 16 - 1)
		result = 0;
	return (result);
}

/*
  The function will populate the array with the values of the map's perimeter
	
Parameters: 
	array_udlr: the two-dimensional array to be populated of type int;
	  the first dimension means "up" (0), "down" (1), "left" (2), and
	  "right" (3); the 2nd dimension goes from left to right, or from up
	  to down.
	arg: The char pointer of the argument entered by the user that must 
        contain digits from 1 to 4 with spaces in between and with 32 characters
        in total counting the \0
*/

void	populate_udlr(int array_udlr[4][4], char *arg)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (arg[i] != '\0')
	{
		if (i % 2 == 0)
		{
			array_udlr[x][y] = ft_atoi(&arg[i]);
			y++;
			if (y == 4)
			{
				y = 0;
				x++;
			}
		}
		i++;
	}
}
