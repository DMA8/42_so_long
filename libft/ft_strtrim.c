/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:22:37 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:22:37 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_set(char chr, char const *set)
{
	int	ind;

	ind = 0;
	if (!set)
		return (0);
	while (set[ind])
	{
		if (set[ind] == chr)
			return (1);
		ind++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dest;
	int		ind;

	start = 0;
	ind = 0;
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_char_in_set(s1[start], set))
		start++;
	while (s1[end] && is_char_in_set(s1[end], set) && end > start)
		end--;
	dest = (char *)malloc(sizeof(char) * (end - start) + 2);
	if (!dest)
		return (NULL);
	while (start <= end)
		dest[ind++] = s1[start++];
	dest[ind] = 0;
	return (dest);
}
