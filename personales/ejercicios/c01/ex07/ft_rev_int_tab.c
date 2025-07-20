/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:02:55 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/17 12:11:11 by rafarauj         ###   ########.fr       */
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

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ((size - 1) / 2))
	{
		ft_rev_int_tab(&tab[i], tab[(size -1 - j)]);
		i++;
		j++;
	}
}
/*
int main()
{
	int	a[] = {1,2,3,4};
	int	i;
	int	size;
	i = 0;
	size = 4;

	ft_rev_int_tab(a, size);

	while (i <= 3)
        {
		printf("%d", a[i]);
		i++;
        }

}
*/
