/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:11 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:18:43 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h> // to use: va_start, va_arg, va_copy, va_end
# include <stddef.h> // to use: size_t
# include "libft.h"

// Flags
typedef struct s_flags
{
	char	minus;
	char	zero;
	char	dot;
	char	hash;
	char	space;
	char	plus;
	int		width;
	int		precision;
}	t_flags;

t_flags	init_flags(void);
void	reset_flags(t_flags *flags);
void	set_flags(char *str_flags, char t, t_flags *flags);
char	*parse_sign(char *num, char is_neg, t_flags flags);
char	*parse_hash(char *num, unsigned long n, char type, t_flags flags);
char	*parse_zero(char *str, char is_neg, t_flags flags);
char	*parse_width(char *str, t_flags flags);
char	*parse_precision_num(char *num, t_flags flags);
char	*parse_precision_str(char *str, t_flags flags);
char	*parse_char(char c, t_flags flags);
char	*parse_int(char *num, char is_neg, t_flags flags);
char	*parse_hexa(char *num, unsigned long n, char type, t_flags flags);

// Write types
# define FT_BASE_HEXA_MIN "0123456789abcdef"
# define FT_BASE_HEXA_MAY "0123456789ABCDEF"
# define FT_BASE_DECIMAL "0123456789"

int		write_char(char c, t_flags flags);
int		write_str(char *str, t_flags flags);
int		write_int(int n, t_flags flags);
int		write_uint(unsigned int n, t_flags flags);
int		write_hexa(unsigned long n, char type, t_flags flags);

# define CONVERSIONS "cspdiuxX%"

int		ft_printf(char const *str, ...);

#endif
