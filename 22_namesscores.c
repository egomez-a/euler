/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_namesscores.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:37:13 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 17:33:52 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strcpy(char *string_dest, const char *string_src)
{
	int	counter;

	counter = 0;
	while (string_src[counter])
	{
		string_dest[counter] = string_src[counter];
		counter++;
	}
	string_dest[counter] = '\0';
	return (string_dest);
}

char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t		ft_begtrim(char const *s1, char const *set)
{
	int beg;

	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	return (beg);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	beg = ft_begtrim(s1, set);
	end = ft_strlen(s1);
	if (beg == end)
	{
		str = malloc(sizeof(char*));
		str[0] = '\0';
		return (str);
	}
	while (s1[end - 1] != '\0' && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char*)malloc(sizeof(char) * (end - beg + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (beg < end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}

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
		i++;
	}
    return (score);
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
	char *filename;
	char **matrix;
    FILE *inputFile;
	char ch;
	int i;
	int j;
	char *ord;
	char *s;
	int names = 0;
	int score;

	s = malloc(46500);
	ord = malloc(20);
	i = 0;
	filename = "p022_names.txt";
	// Opening file in reading mode
	inputFile = fopen(filename, "r" );
	if(inputFile == NULL) 
	{
		printf("Error- Unable to open %s\n", filename);
		return (0);
	}
	// printf("Content of this file is as follows:\n");
	while (1)
	{
		ch = fgetc(inputFile);
		if (ch != EOF)
		{
			s[i] = ch;
			printf("%c", s[i]);
			if (s[i] != '\n')
			i++;
		}
		else
			break;
	}
	printf ("\n");
	// metemos los elementos en una matriz y quitamos comillas
	matrix = ft_split(s, ',');
	i = 0;
	while (matrix[i])
	{
		matrix[i] = ft_strtrim(matrix[i], "\"");
		i++;
	}
	names = i;
	// Ordenamos la lista
	i = 0;
	j = i + 1;
	while (i < names)
	{
		while (j < names)
		{
			if (strcmp(matrix[i], matrix[j]) > 0)
			{
				ft_strcpy(ord, matrix[i]);
				ft_strcpy(matrix[i], matrix[j]);
				ft_strcpy(matrix[j], ord);
			}
			j++;
		}	
		i++;
		j = i + 1;
	}
	// calculamos la longitud de cada cadena y la sumamos a su índice
	i = 0;
	score = 0;
	while (matrix[i])
	{
		score = score + ((i + 1) * ft_namescore(matrix[i]));
		printf("%d %s %d\n", i, matrix[i], score);
		i++;
	}
	fclose(inputFile);
	inputFile = NULL;  // Safety precaution, to prevent trying to use a closed file.
	free(s);
	free(ord);
	return 0;
}