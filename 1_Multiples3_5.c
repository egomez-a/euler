/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_Multiples3_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:11:51 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 15:47:06 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// If we list all the natural numbers below 10 that are multiples of 3 or 5, 
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <stdio.h>

int    main (void)
{
    int i;
    int n;

    i = 2;
    n = 0;
    while (i < 1000)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            printf("  %d   --- ", i);
            n = n + i;
            printf("suma = %d\n", n);
        }
        i++;
    }
    return (n);
}