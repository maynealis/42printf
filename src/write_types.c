/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/22 12:57:41 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "write_types.h"

int	write_char(char c)
{
	return (write(1, &c, 1));
}

int	write_str(char *str)
{
	char	*null_str;
	int		result;

	if (str == NULL)
	{
		null_str = ft_strdup("(null)");
		if (null_str == NULL)
			return (-1);
		result = write(1, null_str, ft_strlen(null_str));
		free(null_str);
		return (result);
	}
	result = write(1, str, ft_strlen(str));
	return (result);
}

int	write_int(int n)
{
	char	*int_str;
	int		len;

	int_str = ft_itoa(n);
	if (int_str == NULL)
		return (-1);
	len = write_str(int_str);
	free(int_str);
	return (len);
}

int	write_uint(unsigned int n)
{
	char	*num;
	int		len;

	num = ft_uitoa_base(n, FT_BASE_DECIMAL);
	if (num == NULL)
		return (-1);
	len = write_str(num);
	free(num);
	return (len);
}

int	write_hexa(unsigned long n, char x, char *prefix)
{
	char	*num;
	char	*str;
	int		len;

	if (x == 'x')
		num = ft_uitoa_base(n, FT_BASE_HEXA_MIN);
	else if (x == 'X')
		num = ft_uitoa_base(n, FT_BASE_HEXA_MAY);
	else
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
	if (num == NULL)
		return (-1);
	str = ft_strjoin(prefix, num);
	if (str == NULL)
		return (-1);
	len = write_str(str);
	free(num);
	free(str);
	return (len);
}
