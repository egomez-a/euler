/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namescore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:23:27 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 17:30:46 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 		ft_namescore(char *s)
{
	int i;
	int score;
	char *c;

	i = 0;
	score = 0;
	while (s[i])
	{
		c = &s[i];
		score = score + *c - 64;
		printf ("%c - %d\n", s[i], (*c - 64));
		i++;
	}
    return (score);
}

int main()
{
    char *s = "COLIN";

    printf("El nombre %s tiene un score de %d", s, ft_namescore(s));
}
