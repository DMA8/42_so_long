/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:22:31 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:22:31 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src_str, int char_to_find)
{
	int	ind;

	ind = ft_strlen(src_str);
	while (ind >= 0)
	{
		if (src_str[ind] == (char)char_to_find)
			return ((char *)src_str + ind);
		ind--;
	}
	return (NULL);
}
