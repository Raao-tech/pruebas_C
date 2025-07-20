/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <rafarauj@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:17:10 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/18 13:38:35 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_int(int nb, int length)
{
	int	i;
	int	coc;
	char	rest;

	i = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		write(1, "-", 1);
	}
	while (i < length)
	{
		rest = '0' + (nb % 10);
		write(1, &rest, 1);
		coc = nb / 10;
		nb = coc;
		i++;
	}
	write(1, "\n", 1);
}

int	ft_length_int(int n, int i)
{
	int	c;

	c = n / 10;
	while (c != 0)
	{
		n = c;
		c = n / 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	int	l;
	int	length;

	l = 1;
	length = ft_length_int(nb, l);
	ft_write_int(nb, length);
}

int main()
{
	ft_putnbr(42);
}
