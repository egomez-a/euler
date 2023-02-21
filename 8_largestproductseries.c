/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_largestproductseries.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:50:07 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/21 14:54:19 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
	char ch;
	char *filename;
	FILE *inputFile;
	int i, j;
	long int p, pmax;
	char *s;
	char *mat;

	s = malloc(1500);
	mat = malloc(1000);
	i = 0;
	j = 0;
	ch = 0;
	filename = "8_1000digitnumber.txt";
	// Opening file in reading mode
	inputFile = fopen(filename, "r" );
	if(inputFile == NULL) 
	{
		printf("Error- Unable to open %s\n", filename);
		return (0);
	}
	printf("Content of this file is as follows:\n");
	while (1)
	{
		ch = fgetc(inputFile);
		if (ch != EOF)
		{
			s[i] = ch;
			printf("%c", s[i]);
			if (s[i] != '\n')
			{	
				mat[j] = atoi(&s[i]);
				j++;
			}
			i++;
		}
		else
			break;
	}
	printf("\ntotal numero de elementos es %d\n", j);
	i = 0;
	while (i < j)
	{
		printf("%d", mat[i]);
		i++;
	}
	printf ("\n");
	fclose(inputFile);
	inputFile = NULL;  // Safety precaution, to prevent trying to use a closed file.
	i = 0;
	pmax = 0;
	while (s[i])
	{
		p = 1;
		j = 0;
		while (j < 13)
		{
			p = mat[i + j] * p;
			j++;
		}
		if (p > pmax)
		{
			pmax = p;
			printf("****PRODUCTO MAXIMO %d es %ld\n", i, pmax);
		}
		i++;	
	}
	
	free(s);
	return 0;
}
