/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_summationprimes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:15:43 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 16:06:12 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

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
				prim = 0;
		}
		i++;
	}
	return (prim);
}

int main (void)
{
	long int n;
	long int sum;

	n = 1;
	sum = 0;
	while (n < 2000000) 
	{
		if (ft_isprime(n) == 1)
		{
			printf ("%ld ", n);
			sum = sum + n;
			n++;
		}
		else
			n++;
	}
	printf ("\nSUM = %ld\n", sum);
}