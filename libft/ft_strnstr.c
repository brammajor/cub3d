/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:40:36 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:40:37 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (little[0] == 0)
		return ((char *)big);
	if (little == NULL || len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && i + little_len - 1 < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (j < little_len && big[i + j] == little[j])
				j++;
			if (j == little_len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char *s = ft_strnstr(haystack, needle, -1);
	printf("string: \"%s\", offset: %ld\n", s, s - haystack);
	return (0);
}
*/
