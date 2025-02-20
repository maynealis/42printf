/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:14:43 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:45:13 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_TYPES_BONUS_H
# define WRITE_TYPES_BONUS_H

# include "libft.h"
# include "parse_precision_bonus.h"
# include "parse_types_bonus.h"
# include "parse_flags_bonus.h"
# include "flags_manager_bonus.h"
# include "utils.h" //TODO _bonus

# define FT_BASE_HEXA_MIN "0123456789abcdef"
# define FT_BASE_HEXA_MAY "0123456789ABCDEF"
# define FT_BASE_DECIMAL "0123456789"

int	write_char(char c, t_flags flags);
int	write_str(char *str, t_flags flags);
int	write_int(int n, t_flags flags);
int	write_uint(unsigned int n, t_flags flags);
int	write_hexa(unsigned long n, char type, t_flags flags);

#endif
