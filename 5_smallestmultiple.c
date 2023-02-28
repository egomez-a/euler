/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_smallestmultiple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:26:30 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 15:51:58 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <stdio.h>

int main (void)
{
    int j;
    int prime[8] = {2, 3, 5, 7, 11, 13, 17, 19}; 
    long int p;
    int pot;
    int top;

    j = 0;
    top = 20;
    p = 1;
    while (j < 8)
    {
        pot = 1;
        pot = prime[j];
        printf("El numero pot es %d\n", pot);
        while (pot < top)
        {
            pot = pot * prime[j];
        }
        pot = pot / prime[j];
        printf("potencia de %d es %d\n", prime[j], pot);
        p = p * pot;
        printf(" = %ld\n", p);
        j++;
    }
}