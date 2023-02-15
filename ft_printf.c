/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tikhacha <tikhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:44:14 by tikhacha          #+#    #+#             */
/*   Updated: 2023/02/15 21:17:11 by tikhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_percentage(char type, va_list arg)
{
	if (type == 'c')
		return (ft_putchr((char) va_arg(arg, char *)));
	else if (type == 's')
		return (ft_putstr((char *) va_arg(arg, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr((int) va_arg(arg, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbrhex((int) va_arg(arg, char *), type));
	else if (type == 'p')
		return (ft_putptrhex((char *) va_arg(arg, char *)));
	else if (type == '%')
		return (ft_putchr('%'));
	return (0);
}

int	ft_printf(const char *arg, ...)
{
	int	len;
	int	i;
	va_list	args;

	i = 0;
	len = 0;
	if (!arg)
		return (0);
	va_start(args, arg);
	while (arg[i])
	{
		while (arg[i] != '%' && arg[i] != '\0' && ++len)
			write (1, &arg[i++], 1);
		if (arg[i] == '%')
		{
			i++;
			len += ft_percentage (arg[i++], args);
		}
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char *a = (char *)malloc(10);
// 	printf(":%d\n", printf("Hello %p", a));
// 	printf(":%d\n", ft_printf("Hello %p", a));
// 	//printf("%d\n", printf("original:Hello %c %s %d %i %x %X %p %%d\n", ' ', "World!", 10, 10, 3000000, 3000000, a));
// 	//printf("%d\n", ft_printf(" ft_copy:Hello %c %s %d %i %x %X %p %%d", ' ', "World!", 10, 10, 3000000, 3000000, a));
// }