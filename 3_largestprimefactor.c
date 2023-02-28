/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_largestprimefactor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:50:50 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 15:50:48 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <stdio.h>

int	ft_isprime(long int n)
{
	long int	prim;
	long int	i;

	prim = 1;
	i = 5;
	if (n == 2 || n == 3)
	{
		prim = 1;
		return (prim);
	}
	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
	{
		prim = 0;
		return (prim);
	}	
	while (i * i <= n)
	{
		if (n % i == 0 || n * (i + 2) == 0)
		{
			if (ft_isprime(i) == 0)
				break ;
			else
			{
				printf("Prime factor of %ld is %ld\n", n, i);
				prim = 0;
			}
		}
		i++;
	}
	return (prim);
}

int main(void)
{
	long int n;

	while (1)
	{
		printf ("Enter an integer: ");
		scanf("%ld", &n);
		if (ft_isprime(n) == 1)
			printf("Number %ld is prime\n", n);
		else
			printf("Number %ld is not a prime\n", n);
	}
}
