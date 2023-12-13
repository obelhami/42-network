/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelhami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:13:47 by obelhami          #+#    #+#             */
/*   Updated: 2023/12/07 15:11:48 by obelhami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	putcharft(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

static void	putsign(char c, int *i, int *count)
{
	write(1, &c, 1);
	(*count)++;
	(*i)++;
}

static int	ft_double_printf(const char *str, int *i, int *count, va_list ptr)
{
	if (str[*i] == '%' && str[*i + 1] == 'c')
	{
		ft_putchar(va_arg(ptr, int), i, count);
		(*i)--;
	}
	else if (str[*i] == '%' && str[*i + 1] == 's')
		ft_putstr(va_arg(ptr, char *), i, count);
	else if (str[*i] == '%' && (str [*i + 1] == 'd' || str[*i + 1] == 'i'))
		ft_putnbr(va_arg(ptr, int), i, count);
	else if (str[*i] == '%' && str [*i + 1] == 'u')
		ft_putunbr(va_arg(ptr, unsigned int), i, count);
	else if (str[*i] == '%' && str [*i + 1] == 'x')
		ft_puthex(va_arg(ptr, int), "0123456789abcdef", i, count);
	else if (str[*i] == '%' && str[*i + 1] == 'X')
		ft_puthex(va_arg(ptr, int), "0123456789ABCDEF", i, count);
	else if (str[*i] == '%' && str[*i + 1] == '%')
		putsign('%', i, count);
	else if (str[*i] == '%' && str[*i + 1] == 'p')
		ft_putptr(va_arg(ptr, unsigned long long), "0123456789abcdef",
			i, count);
	else if (str[*i] == '%' && str[*i + 1] == '\0')
		return (-1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		ptr;
	int			i;
	int			count;

	if (!str)
		return (-1);
	va_start(ptr, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_double_printf(str, &i, &count, ptr) == -1)
				return (-1);
		}
		else
			putcharft(str[i], &count);
		i++;
	}
	va_end(ptr);
	return (count);
}
