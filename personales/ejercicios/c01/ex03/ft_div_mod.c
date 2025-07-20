/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:54:40 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/16 14:03:54 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main()
{
	int	a,	b;
	int	coc,	rest;
	int	*div,	*mod;
	
	div = &coc;
	mod = &rest;

	a = 10;
	b = 5;

	ft_div_mod(a,b,div,mod);

	printf("%d", coc);
	printf("\n");
	printf("%d", rest);

}
*/
