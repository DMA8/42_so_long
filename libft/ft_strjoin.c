/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:21:51 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:21:51 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	init(size_t *a, size_t *b, char const *s1, char const *s2)
{
	*a = ft_strlen(s1);
	*b = ft_strlen(s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	ind;
	char	*ans;

	if (!s1 || !s2)
		return ("");
	init(&len1, &len2, s1, s2);
	ind = 0;
	ans = (char *)malloc(len1 + len2 + 1);
	if (!ans)
		return (NULL);
	while (s1[ind])
	{
		ans[ind] = s1[ind];
		ind++;
	}
	ind = 0;
	while (s2[ind])
	{
		ans[ind + len1] = s2[ind];
		ind++;
	}
	ans[ind + len1] = 0;
	return (ans);
}
