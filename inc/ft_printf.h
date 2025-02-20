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
# include "write_types.h"

int	ft_printf(char const *str, ...);

#endif
