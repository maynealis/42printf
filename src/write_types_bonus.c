/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:36:26 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_char(char c, t_flags flags)
{
	int		result;
	char	*str_to_write;

	result = 0;
	if (c == 0)
		result = 1;
	else if (c == '%')
	{
		result = write(1, &c, 1);
		return (result);
	}
	str_to_write = parse_char(c, flags);
	if (str_to_write == NULL)
		return (-1);
	result += write(1, str_to_write, ft_strlen(str_to_write));
	free(str_to_write);
	return (result);
}

int	write_str(char *str, t_flags flags)
{
	int		result;
	char	*str_to_parse;
	char	*str_precision;
	char	*str_to_write;

	if (str == NULL)
		str_to_parse = ft_strdup("(null)");
	else
		str_to_parse = ft_strdup(str);
	if (str_to_parse == NULL)
		return (-1);
	str_precision = parse_precision_str(str_to_parse, flags);
	str_to_write = parse_width(str_precision, flags);
	result = write(1, str_to_write, ft_strlen(str_to_write));
	free(str_precision);
	free(str_to_write);
	free(str_to_parse);
	return (result);
}

int	write_int(int n, t_flags flags)
{
	int		result;
	char	*num;
	char	is_neg;
	char	*num_to_write;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	num = ft_itoa(n);
	if (num == NULL)
		return (-1);
	num_to_write = parse_int(num, is_neg, flags);
	result = write(1, num_to_write, ft_strlen(num_to_write));
	free(num);
	free(num_to_write);
	return (result);
}

int	write_uint(unsigned int n, t_flags flags)
{
	int		result;
	char	*num;
	char	*num_precision;
	char	*num_padded;

	num = ft_uitoa_base(n, FT_BASE_DECIMAL);
	num_precision = parse_precision_num(num, flags);
	if (flags.zero)
		num_padded = parse_zero(num_precision, 0, flags);
	else
		num_padded = parse_width(num_precision, flags);
	result = write(1, num_padded, ft_strlen(num_padded));
	free(num);
	free(num_precision);
	free(num_padded);
	return (result);
}

int	write_hexa(unsigned long n, char type, t_flags flags)
{
	int		result;
	char	*num;
	char	*num_precision;
	char	*num_parsed;

	if (type == 'x')
		num = ft_uitoa_base(n, FT_BASE_HEXA_MIN);
	else if (type == 'p')
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
	else
		num = ft_uitoa_base(n, FT_BASE_HEXA_MAY);
	num_precision = parse_precision_num(num, flags);
	num_parsed = parse_hexa(num_precision, n, type, flags);
	result = write(1, num_parsed, ft_strlen(num_parsed));
	free(num);
	free(num_precision);
	free(num_parsed);
	return (result);
}
