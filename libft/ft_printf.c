/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:32:57 by syolando          #+#    #+#             */
/*   Updated: 2022/03/06 14:36:33 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

static int	flag_handler(va_list ap, const char *input_str, int *ind)
{
	int	n_printed;
	int	local_ind;

	if (!input_str || !ind)
		return (0);
	*ind += 1;
	local_ind = *ind;
	n_printed = 0;
	if (input_str[local_ind] == 'd' || input_str[local_ind] == 'i')
		n_printed = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (input_str[local_ind] == 'u')
		n_printed = ft_putunsignedint_fd(va_arg(ap, int), 1);
	else if (input_str[local_ind] == 'c')
		n_printed = ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (input_str[local_ind] == '%')
		n_printed = ft_putchar_fd('%', 1);
	else if (input_str[local_ind] == 's')
		n_printed = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (input_str[local_ind] == 'x' || input_str[local_ind] == 'X')
		n_printed = ft_putnbr_hex_fd(va_arg(ap, int), input_str[local_ind], 1);
	else if (input_str[local_ind] == 'p')
		n_printed = ft_put_void_ptr_fd(va_arg(ap, void *), 1);
	*ind += 1;
	return (n_printed);
}

static int	text_handler(const char *input_str, int *ind)
{
	int	start_ind;
	int	n_char_printed;

	if (!input_str || !ind)
		return (0);
	start_ind = *ind;
	while (input_str[*ind] && input_str[*ind] != '%')
		*ind += 1;
	write(1, &input_str[start_ind], *ind - start_ind);
	n_char_printed = *ind - start_ind;
	return (n_char_printed);
}

int	ft_printf(const char *input_str, ...)
{
	int		ind;
	int		len_input_str;
	int		n_printed;
	va_list	ap;

	len_input_str = ft_strlen(input_str);
	ind = 0;
	n_printed = 0;
	va_start(ap, input_str);
	while (ind < len_input_str)
	{
		if (input_str[ind] == '%')
			n_printed += flag_handler(ap, input_str, &ind);
		else
			n_printed += text_handler(input_str, &ind);
	}
	va_end(ap);
	return (n_printed);
}
