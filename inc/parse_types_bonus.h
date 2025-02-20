/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:22:10 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:45:32 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TYPES_BONUS_H
# define PARSE_TYPES_BONUS_H

# include "libft.h"
# include "flags_manager_bonus.h"
# include "parse_precision_bonus.h"
# include "parse_flags_bonus.h"

char	*parse_char(char c, t_flags flags);
char	*parse_int(char *num, char is_neg, t_flags flags);
char	*parse_hexa(char *num, unsigned long n, char type, t_flags flags);

#endif
