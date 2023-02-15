/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_highlydivisibletriangular.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:58:19 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/15 17:47:57 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

double triangle_number(double index)
{
	double t;
    double i;

    t = 0;
    i = 1;
    while (i <= index)
    {
        t = t + i;
        i++;
    }
    return (t);
}

int  divisors(double number)
{
    double i;
    int div;

    div = 0;
    i = 1;
    while (i <= sqrt(number))
    {
        if (remainder (number, i) == 0)
        {
            if (number / i == i)
                div++;
            else
                div = div + 2;
        }
        i++;
    }
    return (div);
}

int main(void)
{
    double  index;
    int     div;
    double  number;
    
    index = 1;
    div = 0;
    number = 0;
    while (index <= 8000000)
    {
        number = triangle_number(index);
        div = divisors(number);
        printf("The triangular number %f with an index of %f has %d divisors\n", number, index, div);
        if (div > 500)
        {
            printf("The triangular number %f with an index of %f has %d divisors\n", number, index, div);
            break;
        }
        index++;
    }
}



// int main(void)
// {
// 	double index;

// 	while (1)
// 	{
// 		printf ("Enter an index: ");
// 		scanf("%lf", &index);
//         printf("El número triangular %fes %f. \n", index, triangle_number(index));
//         printf("Tiene %d divisores\n", divisors(triangle_number(index)));
// 	}
// }