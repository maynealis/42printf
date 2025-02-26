/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:25:27 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:45:51 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*parse_precision_num(char *num, t_flags flags)
{
	char	*zeros;
	size_t	len_num;
	char	*str;

	zeros = NULL;
	len_num = ft_strlen(num);
	if (flags.precision > (int)len_num)
	{
		zeros = ft_calloc(flags.precision - len_num + 1, 1);
		if (zeros)
			zeros = ft_memset(zeros, '0', flags.precision - len_num);
	}
	str = ft_strjoin(zeros, num);
	free(zeros);
	return (str);
}

char	*parse_precision_str(char *str, t_flags flags)
{
	char	*str_result;

	if (flags.precision < (int)ft_strlen(str))
	{
		str_result = ft_substr(str, 0, flags.precision);
		return (str_result);
	}
	else
		str_result = ft_strdup(str);
	return (str_result);
}
