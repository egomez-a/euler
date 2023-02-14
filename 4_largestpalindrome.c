/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_largestpalindrome.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:10:14 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/14 13:22:18 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_numberofdigits(int n)
{
	int	i;

    i = 0;
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_palindrome(int n)
{
	int	rest;
	int	reversed;
	
	rest = 0;
	reversed = 0;
	while (n != 0)
	{
		rest = n % 10;
		reversed = reversed * 10 + rest;
		n = n / 10;		
	}
	return (reversed);
}

int main(void)
{
	int n;
	int m; 
	int p;
	int palinmax;

	m = 999;
	palinmax = 0;
	while (m > 0)
	{	
		n = 999;
		while (n > 0)
		{
			p = n * m;
			if (ft_palindrome(p) == p && p > palinmax)
			{
				printf("the number %d * %d = %d is palindrome\n", n, m, p);
				palinmax = p;
				break;
			}
			n--;
		}
		m--;
	}
	printf("The number %d has %d digits\n", palinmax, ft_numberofdigits(palinmax));
	printf("The palindrome of %d is %d\n", palinmax, ft_palindrome(palinmax));
}
