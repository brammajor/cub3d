/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:38:37 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:38:38 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_str(int n, int *sign, int *digits, char *a)
{
	if (n < 0)
		n = -n;
	if (*sign == 1)
		a[0] = '-';
	a[*sign + *digits] = '\0';
	while (*digits > 0)
	{
		a[*sign + *digits - 1] = n % 10 + '0';
		(*digits)--;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*a;
	int		digits;
	int		sign;
	int		num;

	num = n;
	digits = 1;
	sign = 0;
	if (n < 0)
		sign = 1;
	while (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}
	a = (char *)malloc((sign + digits + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_memmove(a, "-2147483648", 12);
		return (a);
	}
	fill_str(n, &sign, &digits, a);
	return (a);
}
