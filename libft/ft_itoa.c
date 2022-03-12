/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:18:17 by syolando          #+#    #+#             */
/*   Updated: 2021/11/10 17:51:35 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_n_digits_in_int(long n)
{
	int	ndigits;
	int	delimiter;

	ndigits = 0;
	delimiter = 1;
	if (n < 0)
	{
		n *= -1;
		ndigits++;
	}
	while (n / delimiter > 9)
	{
		delimiter *= 10;
		ndigits++;
	}
	return (ndigits + 1);
}

static int	get_start_delim(long n)
{
	int	delimiter;

	if (n < 0)
		n *= -1;
	delimiter = 1;
	while (n / delimiter > 9)
	{
		delimiter *= 10;
	}
	return (delimiter);
}

static void	fill_ans(char *ans, int delim, int ind, long nn)
{
	char	digit;

	while (delim != 0)
	{
		digit = nn / delim;
		nn = nn - digit * delim;
		digit += '0';
		ans[ind] = digit;
		delim /= 10;
		ind++;
	}
	ans[ind] = 0;
}

char	*ft_itoa(int n)
{
	int		start_delimiter;
	char	*ans;
	int		ind;
	long	nn;

	ind = 0;
	nn = n;
	start_delimiter = get_start_delim(nn);
	ans = (char *)malloc((get_n_digits_in_int(nn) + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	if (n < 0)
	{
		ans[0] = '-';
		nn *= -1;
		ind++;
	}
	fill_ans(ans, start_delimiter, ind, nn);
	return (ans);
}
