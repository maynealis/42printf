/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:01:38 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/22 13:01:42 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_TYPES_H
# define WRITE_TYPES_H

# include "libft.h"
//# include "utils.h"
# include <unistd.h>

# define FT_BASE_HEXA_MIN "0123456789abcdef"
# define FT_BASE_HEXA_MAY "0123456789ABCDEF"
# define FT_BASE_DECIMAL "0123456789"

int		write_char(char c);
int		write_str(char *str);
int		write_int(int n);
int		write_uint(unsigned int n);
int		write_hexa(unsigned long n, char x, char *prefix);

#endif
