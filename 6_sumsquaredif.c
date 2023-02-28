/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sumsquaredif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:10:14 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 15:53:45 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The sum of the squares of the first ten natural numbers is 385 (1^2 + 2^2 + ... + 10^2)
// The square of the sum of the first ten natural numbers is, (1+2+...+10)^2 = 55^2 = 3025

// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 
// 3025 - 285 = 2640.

// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <stdio.h>

int main(void)
{
	int n;
    int i;
    int squares;
    int sumsquares;
    int sum;
    int squaresum;

    i = 1;
    n = 100;
    sumsquares = 0;
    squaresum = 0;
    squares = 0;
    sum = 0;
    while (i <= n)
    {
        squares = i * i;
        sumsquares = squares + sumsquares;
        i++;
    }
    printf("sum of the squares of %d numbers is %d\n", n, sumsquares);
    i = 1;
    while (i <= n)
    {
        sum = sum + i;
        i++;
    }
    squaresum = sum * sum; 
    printf("square of sum of %d numbers is %d\n", n, squaresum);
    printf("Difference is %d", squaresum - sumsquares);   
}
