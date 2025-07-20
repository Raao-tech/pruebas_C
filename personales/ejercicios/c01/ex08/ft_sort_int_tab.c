/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:16:04 by rafarauj          #+#    #+#             */
/*   Updated: 2025/07/17 16:32:49 by rafarauj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	o;

	i = 0;
	j = size - 1;
	o = 0;

	while (i <= (size - 1))
	{
		while (o <= size -1)
		{
			if (tab[o] > tab[size - 1 - o])
				printf("Pasaría de  %d  a  %d \n", tab[o], tab[size - 1 - o]);
				ft_swap(&tab[o],&tab[size -1 - 0]);
			printf("%d \n", tab[o]);
			o++;
		}

		
		i++;
	}
}

int main()
{
        int     a[] = {4,3,2,1};
        int     i;
        i = 0;

        ft_sort_int_tab(a, 4);

        while (i <= 3)
        {
                printf("\n %d", a[i]);
                i++;
        }

}

