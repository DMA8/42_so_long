/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:20:20 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:20:20 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t nbytes)
{
	size_t	ind;

	if (!dest && !src)
		return (NULL);
	ind = 0;
	while (ind < nbytes)
	{
		*(unsigned char *)(dest + ind) = *(unsigned char *)(src + ind);
		ind++;
	}
	return (dest);
}
