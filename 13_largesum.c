/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_largesum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:55:20 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/21 15:26:27 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
	int i, f, c;
	char *s;
	char **matchar;
	char **matdig;

	s = malloc(5101);
	matdig = malloc(5550);
	i = 0;
	f = 0;
	c = 0;
	ch = 0;
	filename = "13_100_50digit_number.txt";
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
	matchar = ft_split(s, '\n');
	f = 0;
	while (f < 100)
	{
		c = 0;
		while (c < 50)
		{
			matdig[f][c] = atoi(&matchar[f][c]);
			printf("%d", matdig[f][c]);
			c++;
		}
		f++;
	}
}