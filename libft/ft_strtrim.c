/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:40:45 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:40:46 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	len = ft_strlen(s1);
	while (len > 0 && len > i && in_set(s1[len - 1], set))
		len--;
	trim = (char *)malloc((len - i + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	j = 0;
	while (i < len)
		trim[j++] = s1[i++];
	trim[j] = '\0';
	return (trim);
}
