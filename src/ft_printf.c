/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/22 12:59:10 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_subst(char type, va_list args)
{
	void	*arg;

	if (type == 'c')
		return (write_char(va_arg(args, int)));
	else if (type == '%')
		return (write_char('%'));
	else if (type == 's')
		return (write_str(va_arg(args, char *)));
	else if (type == 'p')
	{
		arg = va_arg(args, void *);
		if (arg == NULL)
			return (write_str("(nil)"));
		return (write_hexa((unsigned long)arg, type, "0x"));
	}
	else if (type == 'd' || type == 'i')
		return (write_int(va_arg(args, int)));
	else if (type == 'u')
		return (write_uint(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (write_hexa(va_arg(args, unsigned int), type, NULL));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	int		temp;
	va_list	args;
	size_t	i;

	va_start(args, str);
	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			temp = write_subst(str[i], args);
		}
		else
			temp = write_char(str[i]);
		if (temp == -1)
			return (-1);
		result += temp;
		i++;
	}
	va_end(args);
	return (result);
}
