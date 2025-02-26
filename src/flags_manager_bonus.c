/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:59:29 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:38:38 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = -1;
	flags->precision = -1;
}

t_flags	init_flags(void)
{
	t_flags	flags;

	reset_flags(&flags);
	return (flags);
}

void	set_flags(char *str_flags, char t, t_flags *flags)
{
	int	i;

	if (ft_strchr(str_flags, '#') && (t == 'x' || t == 'X'))
		flags->hash = 1;
	if (ft_strchr(str_flags, '+') && (t == 'd' || t == 'i'))
		flags->plus = 1;
	if (ft_strchr(str_flags, ' ') && (t == 'd' || t == 'i') && !flags->plus)
		flags->space = 1;
	if (ft_strchr(str_flags, '-'))
		flags->minus = 1;
	if (ft_strchr(str_flags, '.'))
		flags->dot = 1;
	if (flags->dot)
		flags->precision = ft_atoi(ft_strchr(str_flags, '.') + 1);
	i = 0;
	while (str_flags[i] != '\0' && str_flags[i] != '.')
	{
		if (str_flags[i] == '0' && (i == 0 || !ft_isdigit(str_flags[i - 1])))
			flags->zero = 1;
		else if (ft_isdigit(str_flags[i]) && flags->width == -1)
			flags->width = ft_atoi(str_flags + i);
		i++;
	}
}
