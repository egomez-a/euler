/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_longestcollatz.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:52:34 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 16:08:16 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// The following iterative sequence is defined for the set of positive integers:
//    n → n/2 (n is even)
//    n → 3n + 1 (n is odd)
// Using the rule above and starting with 13, we generate the following sequence:
//    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
// Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
// Which starting number, under one million, produces the longest chain?
// NOTE: Once the chain starts the terms are allowed to go above one million.

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