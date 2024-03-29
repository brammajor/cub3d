/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:39:16 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:39:17 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_specifier(const char specifier, va_list ap)
{
	int	printed;	

	printed = 0;
	if (specifier == 's')
		printed += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		printed += print_nbr(va_arg(ap, int));
	else if (specifier == 'i')
		printed += print_nbr(va_arg(ap, int));
	else if (specifier == 'c')
		printed += print_char(va_arg(ap, int));
	else if (specifier == 'u')
		printed += print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		printed += print_hex(va_arg(ap, unsigned int), specifier);
	else if (specifier == 'p')
		printed += print_hex(va_arg(ap, unsigned long long), 'p');
	else if (specifier == '%')
		printed += print_char('%');
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		printed;	

	va_start(ap, format);
	printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			printed += print_char(format[i]);
		if (format[i] == '%')
			printed += parse_specifier(format[++i], ap);
		i++;
	}
	va_end(ap);
	return (printed);
}
