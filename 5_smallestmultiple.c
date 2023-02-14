/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_smallestmultiple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:26:30 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/14 15:25:31 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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