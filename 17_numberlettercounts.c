/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_numberlettercounts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:35:30 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 15:25:32 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_to_words(char *num)
{
    int len;
	int sum;
	int i;
	int lenchain;
	char *string = NULL;
    char *single_digits[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    char *two_digits[] = { "", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    char *tens_multiple[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty",  "seventy", "eighty", "ninety" };
    char *tens_power[] = { "hundred", "thousand" };

	string = malloc(1000);	
	len = strlen(num); // Get number of digits in given number
	printf("%s: ", num);
    if (len == 1) 
	{
        string = strcat(string, single_digits[*num - '0']);
		lenchain = strlen(string);
		printf("%s   %d\n", string, lenchain);
        return (lenchain) ;
    }
	while (*num != '\0') 
	{
        /* Code path for first 2 digits */
        if (len >= 3) 
		{
            if (*num - '0' != 0) 
			{
                string = strcat(string, single_digits[*num - '0']);
				string = strcat(string, tens_power[len - 3]); // here len can be 3 or 4
				if (len == 3 && (*(num + 1) != 0 && (num + 2) != 0))
				{
					string = strcat(string, "and");
				}
            }
            --len;
        }
        /* Code path for last 2 digits */
        else 
		{
            /* Need to explicitly handle 10-19. Sum of the two digits is used as index of "two_digits" array of strings */
            if (*num == '1') 
			{
                sum = *num - '0' + *(num + 1) - '0';
				string = strcat(string, two_digits[sum]);
				lenchain = strlen(string);
				printf("%s   %d\n", string, lenchain);
        		return (lenchain);
            }
  
            /* Need to explicitly handle 20 */
            else if (*num == '2' && *(num + 1) == '0') 
			{
                string = strcat(string, "twenty");
				lenchain = strlen(string);
				printf("%s   %d\n", string, lenchain);
        		return (lenchain);
            }
            /* Rest of the two digit numbers i.e., 21 to 99 */
            else 
			{
                i = *num - '0';
				if (i != 0)
					string = strcat(string, tens_multiple[i]);
                ++num;
                if (*num != '0')
                    string = strcat(string, single_digits[*num - '0']);
            }
        }
        ++num;
    }
	lenchain = strlen(string);
	printf("%s   %d\n", string, lenchain);
    return (lenchain);
}

char		*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = 0;
	while (s1[len])
		len++;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	ft_nblen(long nb)
{
	int len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len = 1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nblen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		str[len] = '0' + (n % 10);
		n = n / 10;
		len--;
	}
	return (str);
}

int main(void)
{
    int n;
	char *num;
	int lenchain;
	int lenght;
	
	lenchain = 0;
	lenght = 0;
	n = 1;
	// printf("Enter number: ");
	// scanf("%d", &n);
	while (n < 1001)
	{
		num = ft_itoa(n);
		lenchain = convert_to_words(num);
		lenght = lenght + lenchain;
		n++;
	}
	lenght = lenght - 27;
	printf ("Total lenght is %d\n", lenght);
    return 0;
}
