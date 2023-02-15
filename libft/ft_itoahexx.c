/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahexx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:45:03 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/15 13:45:32 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_lenght(unsigned int n)
{
	int	k;

	k = 0;
	if (n <= 0)
		k++;
	while (n != 0)
	{
		n /= 16;
		k++;
	}
	return (k);
}

static char	ft_chr(unsigned int n, int lenght)
{
	while (--lenght)
		n /= 16;
	n %= 16;
	if (n < 0)
		n *= -1;
	if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else if (n == 15)
		return ('F');
	return (n + '0');
}

char	*ft_itoahexx(unsigned int n)
{
	char	*p;
	int		i;
	int		lenght;

	i = 0;
	lenght = ft_lenght(n);
	p = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!p)
		return (0);
	if (n < 0)
	{
		p[i++] = '-';
		lenght--;
	}
	while (lenght)
		p[i++] = ft_chr(n, lenght--);
	p[i] = '\0';
	return (p);
}
