/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:21:38 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:21:38 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ans;
	int		len_src;
	int		ind;

	ind = 0;
	len_src = ft_strlen(str);
	ans = (char *)malloc((len_src + 1) * sizeof(char ));
	if (!ans)
		return (NULL);
	while (ind < len_src)
	{
		ans[ind] = str[ind];
		ind++;
	}
	ans[ind] = 0;
	return (ans);
}
