/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:38:28 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/15 03:08:57 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	coma(char a, char b, char c, char d)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a != '9' || b != '8' || c != '9' || d != '9')
	{
		write(1, ", ", 2);
	}
}

void	ultimo(char a, char b, char c, char d)
{
	while (a <= '9')
	{
		while (b < '9')
		{
			while (c <= '9')
			{
				while (d <= '9')
				{
					coma(a, b, c, d);
					d++;
				}
				c++;
				d = '0';
			}
			b++;
			c = '0';
			d = '2';
		}
		a++;
		b = '0';
	}
}

void	ft_print_comb2(void)
{
	char	n[4];

	n[0] = '0';
	n[1] = '0';
	n[2] = '0';
	n[3] = '1';
	ultimo(n[0], n[1], n[2], n[3]);
}
