/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_sundays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:44:06 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/28 18:12:31 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int dayinmonth(int month, int year)
{
    int maxday;
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
        maxday = 30;
    else if (month == 2 && year % 4 != 0)
        maxday = 28;
    else if (month == 2 && year % 4 == 0)
    {
        if (year % 100 == 0)
            maxday = 29;
        else
            maxday = 28;
    }
    else
        maxday = 31;
    return (maxday);
}

int main ()
{
    char *week[] = { "mon", "tue", "wed", "thu", "fri", "sat", "sun" };
    int day;
    int maxday;
    int month;
    int year;
    int factor;

    factor = 0;
    year = 1900;
    while (year < 1901)
    {
        month = 1;
        while (month <= 12)
        {
            day = 1;
            maxday = dayinmonth(month, year);
            while (day <= maxday)
            {
                printf("%d %d %d %s\n", day, month, year, week[day % 7 + factor]);
                day++;
            }
            month++;
        }
        factor = day % 7;
        year++;
    }
}