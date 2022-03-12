/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:22:02 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:22:02 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t nbytes)
{
	size_t	ind;
	size_t	src_len;

	ind = 0;
	src_len = ft_strlen(src);
	if (!nbytes)
		return (src_len);
	while (ind < (nbytes - 1) && src[ind])
	{
		dst[ind] = src[ind];
		ind++;
	}
	dst[ind] = 0;
	ind = 0;
	return (src_len);
}
