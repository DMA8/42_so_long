/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:20:24 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:20:24 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t nbytes)
{
	unsigned char	*src2;
	unsigned char	*dst2;

	if (!dest && !src)
		return (NULL);
	dst2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dst2 > src2)
	{
		while (nbytes--)
			*(dst2 + nbytes) = *(src2 + nbytes);
	}
	else
	{
		while (nbytes--)
			*(dst2++) = *(src2++);
	}
	return (dest);
}
