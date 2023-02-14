/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_evenfibonacci.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:27:27 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/14 10:43:53 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int ft_fibonacci(int index);

int main(void)
{
	int index;
    int n;

	index = 35;
    n = 0;
    while (index > 0)
    {
        printf("El número de fibonacci en la posicio %d es %d\n", index, ft_fibonacci(index + 1));
        if (ft_fibonacci(index + 1) % 2 == 0 && ft_fibonacci(index + 1) <= 4000000)
        {
            n = n + ft_fibonacci(index + 1);
            printf("suma par es %d\n", n);
        }
        index--;
    }
    return (n);
}