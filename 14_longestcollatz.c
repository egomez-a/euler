/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_longestcollatz.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:52:34 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/15 18:17:17 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long int    collatz(long int n)
{
    long int i;

	i = 1;
	// printf("Term %ld is %ld\n", i, n);
	while (n > 1)
	{
		if (n % 2 == 0)
		{
			i++;
			n = n / 2;
			// printf("Term %ld is %ld\n", i, n);
		}
		else
		{
			i++;
			n = 3 * n + 1;
			// printf("Term %ld is %ld\n", i, n);
		}
	}
	return (i);
}

int main(void)
{
    long int n;
    long int terms;
	long int	max;
	long int nummax;
    
  	n = 999999;
	terms = 0;
	max = 0;
    while (n > 1000)
    {
		terms = collatz(n);
		if (terms > max)
		{
			max = terms;
			nummax = n;
		}
		n--;
    }
	printf("El número %ld produce una serie máxima de %ld términos", nummax, max);
	return (max);
}


// int main(void)
// {
// 	int n;

// 	while (1)
// 	{
// 		printf ("Enter an initial number: ");
// 		scanf("%d", &n);
//         printf("Total numero de terms es %d\n", collatz(n));
// 	}
// }