/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:22:42 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:22:42 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*dest;
	size_t	ind;
	size_t	bcopied;

	if (!src)
		return (NULL);
	ind = 0;
	if (len > (size_t)(ft_strlen(src)))
		len = (size_t)(ft_strlen(src));
	bcopied = 0;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (src[ind])
	{
		if (ind >= start && bcopied < len)
		{
			dest[bcopied] = src[ind];
			bcopied++;
		}
		ind++;
	}
	dest[bcopied] = 0;
	return (dest);
}
