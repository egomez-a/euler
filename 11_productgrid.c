/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_productgrid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:07:33 by egomez-a          #+#    #+#             */
/*   Updated: 2023/03/08 12:48:03 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// What is the greatest product of four adjacent numbers in the same direction
// (up, down, left, right, or diagonally) in the 20×20 grid?

static int		ft_countwords(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	if (!s || s[0] == 0)
		return (0);
	i = 0;
	cntr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			cntr++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (cntr);
}

static char		**ft_malloc(char const *s, char c)
{
	int			len;
	char		**tab;

	len = ft_countwords(s, c);
	tab = malloc(sizeof(*tab) * (len + 1));
	if (tab == 0)
		return (0);
	return (tab);
}

static int		ft_wordcountnext(char const *s, char c, int i)
{
	int	cntr;

	cntr = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		cntr++;
		i++;
	}
	return (cntr);
}

static char		**ft_freesplit(char **tab, int i)
{
	int j;

	j = 0;
	while (j < i && tab[j] != 0)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		j;
	char	**tab;

	i = -1;
	start = 0;
	if (s == 0)
		return (0);
	if (!(tab = ft_malloc(s, c)))
		return (0);
	while (++i < ft_countwords(s, c))
	{
		j = 0;
		if (!(tab[i] = malloc(ft_wordcountnext(s, c, start) + 1)))
			return (ft_freesplit(tab, i));
		while (s[start] != '\0' && s[start] == c)
			start++;
		while (s[start] != '\0' && s[start] != c)
			tab[i][j++] = s[start++];
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}

int main ()
{
    char ch;
	char *filename;
	FILE *inputFile;
	int i, f;
	char *s;
	char **matrix = NULL;

	s = malloc(1201);
	matrix = malloc (20);
	i = 0;
	ch = 0;
	filename = "11_numbers.txt";
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
			i++;
		}
		else
			break;
	}
	f = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\n')
		{
			matrix[f] = *ft_split(&s[i], ' ');
			i++;
		}
		printf("%s\n", matrix[f]);
		f++;
	}
}
