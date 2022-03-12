/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:22:18 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:22:18 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	ind;

	ind = 0;
	while (ind < n)
	{
		if (str1[ind] != str2[ind] || (!str1[ind] && !str2[ind]))
			return ((unsigned char)str1[ind] - (unsigned char)str2[ind]);
		ind++;
	}
	return (0);
}
