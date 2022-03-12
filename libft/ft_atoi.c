/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:17:08 by syolando          #+#    #+#             */
/*   Updated: 2021/10/27 12:17:08 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_space(const char c)
{
	if (c == '\v' || c == '\t' || c == '\n'
		|| c == ' ' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static void	init(int *a, long *b, long *c)
{
	*a = 0;
	*b = 1;
	*c = 0;
}

int	ft_atoi(const char *s)
{
	int		str_index;
	long	sign;
	long	result;

	init(&str_index, &sign, &result);
	while (is_space(s[str_index]))
		str_index++;
	if (s[str_index] == '-')
	{
		str_index++;
		sign = -1;
	}
	else if (s[str_index] == '+')
		str_index++;
	while (s[str_index] >= '0' && s[str_index] <= '9')
	{
		result = (result * 10) + (s[str_index] - '0');
		str_index++;
	}
	return ((int)result * sign);
}
