/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:16:59 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/23 16:27:39 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_types_bonus.h"

char	*parse_char(char c, t_flags flags)
{
	char	*padded;
	char	*str_result;
	char	*c_ptr;

	c_ptr = (char *)ft_calloc(2, sizeof(char));
	c_ptr[0] = c;
	padded = NULL;
	if (flags.width > 1)
		padded = ft_calloc(flags.width, 1);
	if (flags.width > 1 && (flags.minus || (!flags.minus && !flags.zero)))
		padded = ft_memset(padded, ' ', flags.width - 1);
	else if (flags.zero && flags.width > 1)
		padded = ft_memset(padded, '0', flags.width - 1);
	if ((flags.zero && c != '%') || flags.minus)
		str_result = ft_strjoin(c_ptr, padded);
	else
		str_result = ft_strjoin(padded, c_ptr);
	free(padded);
	free(c_ptr);
	return (str_result);
}

char	*parse_int(char *num, char is_neg, t_flags flags)
{
	char	*num_precision;
	char	*num_sign;
	char	*num_zero;
	char	*num_padded;

	num_precision = parse_precision_num(num + is_neg, flags);
	num_zero = parse_zero(num_precision, is_neg, flags);
	num_sign = parse_sign(num_zero, is_neg, flags);
	num_padded = parse_width(num_sign, flags);
	free(num_precision);
	free(num_sign);
	free(num_zero);
	return (num_padded);
}

char	*parse_hexa(char *num, unsigned long n, char type, t_flags flags)
{
	char	*parse1;
	char	*parse2;

	if (flags.zero && flags.dot)
	{
		parse1 = parse_hash(num, n, type, flags);
		parse2 = parse_zero(parse1, 0, flags);
	}
	else if (flags.zero && !flags.dot)
	{
		if (flags.hash)
			parse1 = parse_zero(num, 2, flags);
		else
			parse1 = parse_zero(num, 0, flags);
		parse2 = parse_hash(parse1, n, type, flags);
	}
	else
	{
		parse1 = parse_hash(num, n, type, flags);
		parse2 = parse_width(parse1, flags);
	}
	free(parse1);
	return (parse2);
}
