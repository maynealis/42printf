/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:11 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 12:43:46 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // to use: va_start, va_arg, va_copy, va_end
# include <stddef.h> // to use: size_t
# include <unistd.h>
# include "libft.h"

# define FT_BASE_HEXA_MIN "0123456789abcdef"
# define FT_BASE_HEXA_MAY "0123456789ABCDEF"
# define FT_BASE_DECIMAL "0123456789"

int	write_char(char c);
int	write_str(char *str);
int	write_int(int n);
int	write_uint(unsigned int n);
int	write_hexa(unsigned long n, char x, char *prefix);

int	ft_printf(char const *str, ...);

#endif
