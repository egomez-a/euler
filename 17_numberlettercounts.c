/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_numberlettercounts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:35:30 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 11:54:53 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_to_words(char* num)
{
    int len;
	char *string = NULL;
    char *single_digits[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    char *two_digits[] = { "", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    char *tens_multiple[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty",  "seventy", "eighty", "ninety" };
    char *tens_power[] = { "hundred", "thousand" };

	string = malloc(1000);	
	len = strlen(num); // Get number of digits in given number
    /* Base cases */
    if (len == 0) 
	{
        fprintf(stderr, "empty string\n");
        return;
    }
    if (len > 4) 
	{
        fprintf(stderr, "Length more than 4 is not supported\n");
        return;
    }
	printf("\n%s: ", num);
    if (len == 1) 
	{
        string = strcat(string, single_digits[*num - '0']);
		printf("%s\n", string);
		// printf("%s\n", single_digits[*num - '0']);
        return;
    }
	while (*num != '\0') 
	{
        /* Code path for first 2 digits */
        if (len >= 3) 
		{
            if (*num - '0' != 0) 
			{
                printf("%s ", single_digits[*num - '0']);
                printf("%s ", tens_power[len - 3]); // here len can be 3 or 4
				if (len == 3 && (*(num + 1) != 0 && (num + 2) != 0))
					printf("and ");
            }
            --len;
        }
        /* Code path for last 2 digits */
        else {
            /* Need to explicitly handle 10-19. Sum of the two digits is used as index of "two_digits" array of strings */
            if (*num == '1') 
			{
                int sum = *num - '0' + *(num + 1) - '0';
                printf("%s\n", two_digits[sum]);
                return;
            }
  
            /* Need to explicitly handle 20 */
            else if (*num == '2' && *(num + 1) == '0') 
			{
                printf("twenty\n");
                return;
            }
            /* Rest of the two digit numbers i.e., 21 to 99 */
            else 
			{
                int i = *num - '0';
                printf("%s ", i ? tens_multiple[i] : "");
                ++num;
                if (*num != '0')
                    printf("%s ", single_digits[*num - '0']);
            }
        }
        ++num;
    }
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
	
	n = 0;
	printf("Enter number: ");
	scanf("%d", &n);
	num = ft_itoa(n);
	convert_to_words(num);
  
    return 0;
}
