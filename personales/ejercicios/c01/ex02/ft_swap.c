/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:54:56 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/16 13:53:22 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int main()
{
	int	num1;
	int	num2;

	int	*a;
	int	*b;

	num1 = 42;
	num2 = 99;

	a = &num1;
	b = &num2;
	ft_swap(a,b);

	printf("%d", num1);
	printf("%d", num2);
}
*/
