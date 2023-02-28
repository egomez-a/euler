/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_specialPythagoreantriplet.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:57:57 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 16:05:38 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

int main (void)
{
	int a;
	int b;
	int c;
	int product;

	a = 1;
	while (a < 1000)
	{
		b = 2; 
		while (b < 1000)
		{
			c = 3;
			while (c < 1000)
			{
				// printf("Tryplet %d %d %d\n", a, b, c);
				if (a < b && b < c && a < c && (a * a + b * b == c * c))
				{
					printf("Pythagorean triplet!!! %d %d %d", a, b, c);
					if (a + b + c == 1000)
					{
						printf ("************\n");
						product = a * b * c;
					}
					else 
						printf ("\n");
				}
				c++;
			}
			b++;
		}
		a++;
	}
	printf("The answer is %d\n", product);
}