/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalgarra <lalgarra@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:22:35 by lalgarra          #+#    #+#             */
/*   Updated: 2025/07/19 12:49:10 by lalgarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  Converts 'chr' to int.
Paramenters:
	chr: a string that only contains digits ('0'-'9').
*/
int	ft_atoi(char *chr)
{
	int	num_digits;
	int	my_int;

	num_digits = 0;
	while (*(chr + num_digits) >= '0' && *(chr + num_digits) <= '9')
		num_digits++;
	my_int = 0;
	while (num_digits > 0)
	{
		my_int = my_int * 10 + (*(chr + num_digits - 1) - '0');
		num_digits--;
	}
	return (my_int);
}
