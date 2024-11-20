/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:26:44 by imiqor            #+#    #+#             */
/*   Updated: 2024/11/19 00:39:52 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putnumber(int n, int *len)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48, len);
	}
	else
	{
		ft_putnumber(nb / 10, len);
		ft_putnumber(nb % 10, len);
	}
	(void)len;
}
void	ft_str(char *s, int *len)
{
	int		i;
	char	*null;

	i = 0;
	if (!s)
	{
		null = "(null)";
		while (null[i])
		{
			ft_putchar(null[i++], len);
		}
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i++], len);
	}
}
void	ft_put_unsigned_nbr(unsigned int n, int *len)
{
	if (n < 10)
	{
		ft_putchar(n + 48, len);
	}
	else
	{
		ft_putnumber(n / 10, len);
		ft_putnumber(n % 10, len);
	}
	(void)len;
}
void	ft_pointerr(unsigned long nb, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nb > 15)
		ft_pointerr(nb / 16, len);
	ft_putchar(hexa[nb % 16], len);
}

void	ft_pointer(unsigned long nb, int *len)
{
	ft_putchar('0', len);
	ft_putchar('x', len);
	ft_pointerr(nb, len);
}
void	check_and_fetch(char format, int *len, va_list params)
{
	if (format == 'i' || format == 'd')
		ft_putnumber(va_arg(params, int), len);
	else if (format == 's')
		ft_str(va_arg(params, char *), len);
	else if (format == 'c')
		ft_putchar(va_arg(params, int), len);
	else if (format == '%')
		ft_putchar('%', len);
	else if (format == 'u')
		ft_put_unsigned_nbr(va_arg(params, unsigned int), len);
	else if (format == 'p')
		ft_pointer(va_arg(params, unsigned long), len);
	else
		--len;
}
int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		len;
	int		i;

	va_start(params, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_and_fetch(format[i], &len, params);
		}
		else
		{
			ft_putchar(format[i], &len);
		}
		i++;
	}
	return (len);
}
int	main(void)
{
	unsigned int i;
	i = 20000;

	ft_printf("%p", 0);
}