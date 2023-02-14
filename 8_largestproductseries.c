/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_largestproductseries.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:50:07 by egomez-a          #+#    #+#             */
/*   Updated: 2023/02/14 19:56:05 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main (int fd, char **line)
{
	int ret;
	char buf[1000];
	
	ret = 1;
	if (fd < 0 || !line)
		return (-1);
	if (!stvar)
		stvar = ft_strdup("");
	ret = read(fd, buf, 1000)
}