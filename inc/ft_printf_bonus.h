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

# include "flags_manager_bonus.h" // for the struct
# include "write_types_bonus.h"

# define CONVERSIONS "cspdiuxX%"

int		ft_printf(char const *str, ...);

#endif
