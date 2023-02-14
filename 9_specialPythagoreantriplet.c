/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_specialPythagoreantriplet.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:57:57 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/14 20:14:27 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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