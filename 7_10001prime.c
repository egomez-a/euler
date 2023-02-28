/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_10001prime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:32:33 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 16:03:31 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

// What is the 10 001st prime number?

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
				prim = 0;
		}
		i++;
	}
	return (prim);
}

int main(void)
{
	long int n;
	int count; 
	
	count = 1; 
	n = 1;
	while (count < 10002) 
	{
		if (ft_isprime(n) == 1)
		{
			printf("%d -- Number %ld is prime\n", count, n);
			count++;
		}
		n++;
	}
}