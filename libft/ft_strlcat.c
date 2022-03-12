/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:21:57 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:21:57 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t nbytes)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	ind;

	ind = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (nbytes < len_dst + 1)
		return (nbytes + len_src);
	else
	{
		while (src[ind] && len_dst + ind < nbytes - 1)
		{
			dst[len_dst + ind] = src[ind];
			ind++;
		}
	}
	dst[len_dst + ind] = 0;
	return (len_dst + len_src);
}
