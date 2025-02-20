/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:00:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:17:56 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_subst(char type, va_list args, t_flags flags)
{
	void	*arg;

	if (type == 'c')
		return (write_char(va_arg(args, int), flags));
	else if (type == '%')
		return (write_char('%', flags));
	else if (type == 's')
		return (write_str(va_arg(args, char *), flags));
	else if (type == 'p')
	{
		arg = va_arg(args, void *);
		if (arg == NULL)
			return (write_str("(nil)", flags));
		flags.hash = 1;
		return (write_hexa((unsigned long)arg, type, flags));
	}
	else if (type == 'd' || type == 'i')
		return (write_int(va_arg(args, int), flags));
	else if (type == 'u')
		return (write_uint(va_arg(args, unsigned int), flags));
	else if (type == 'x' || type == 'X')
		return (write_hexa(va_arg(args, unsigned int), type, flags));
	return (-1);
}

char	*find_conversion(char *str)
{
	char	*conversion;
	char	*temp;
	int		i;

	conversion = NULL;
	i = 0;
	while (i < 9)
	{
		temp = ft_strchr(str, CONVERSIONS[i]);
		if (temp == NULL)
			i++;
		else
		{
			if (conversion == NULL || (conversion != NULL && temp < conversion))
				conversion = temp;
			i++;
		}
	}
	return (conversion);
}

int	parse_and_write_subst(char **str, va_list args, t_flags flags)
{
	char	*conv;
	char	*str_flags;
	int		result;

	conv = find_conversion(*str + 1);
	str_flags = ft_substr(*str, 0, conv - *str + 1);
	set_flags(str_flags, *conv, &flags);
	result = write_subst(*conv, args, flags);
	free(str_flags);
	*str = conv + 1;
	reset_flags(&flags);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;
	char	*str_ptr;
	t_flags	flags;

	flags = init_flags();
	str_ptr = (char *)str;
	va_start(args, str);
	result = 0;
	while (*str_ptr != '\0')
	{
		if (*str_ptr == '%')
			result += parse_and_write_subst(&str_ptr, args, flags);
		else
		{
			result += write(1, str_ptr, 1);
			str_ptr++;
		}
	}
	va_end(args);
	return (result);
}
