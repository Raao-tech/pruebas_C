/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:05:36 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/16 14:15:08 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	rest;
	int	coc;

	coc = *a / *b;
	rest = *a % *b;
	*a = coc;
	*b = rest;
}
/*
int main()
{
	int	coc,	rest;
	int	*a,	*b;

	coc = 50;
	rest = 10;
	a = &coc;
	b = &rest;

	ft_ultimate_div_mod(a,b);

	printf("%d", coc);
	printf("\n");
	printf("%d", rest);
}
*/
