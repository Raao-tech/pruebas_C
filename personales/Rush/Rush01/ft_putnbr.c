/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalgarra <lalgarra@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 00:34:12 by lalgarra          #+#    #+#             */
/*   Updated: 2025/07/19 18:28:04 by lalgarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

/*
  Computes 10 ^ exp;
Input:
	exp: exponent, >= 10
Returns:
	10 ^ exp; when exp == 0, returns 1
*/
int	ft_pow10(int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result = result * 10;
		exp--;
	}
	return (result);
}

/*
  Writes on stdout the number in nb
*/
void	ft_putnbr(int nb)
{
	int		digits;
	int		pw;
	char	chr;
	int		write_zeroes;

	digits = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -1 * nb;
	}
	while (nb / ft_pow10(digits - 1) > 0)
		digits++;
	write_zeroes = 0;
	while (digits > 0)
	{
		pw = ft_pow10(digits - 1);
		chr = '0' + (nb / pw);
		if (chr > '0')
			write_zeroes = 1;
		if (write_zeroes || chr != '0')
			write(1, &chr, 1);
		nb = nb % pw;
		digits --;
	}
}

/*
  Writes on stdout a representation of ar.
*/
void	ft_put_ar(int ar[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putnbr(ar[row][col]);
			col++;
			if (col < 4)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		row++;
	}
}
