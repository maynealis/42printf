/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:39:07 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/23 16:43:06 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FLAGS_BONUS_H
# define PARSE_FLAGS_BONUS_H

# include "libft.h"
# include "ft_printf_bonus.h"

char	*parse_sign(char *num, char is_neg, t_flags flags);
char	*parse_hash(char *num, unsigned long n, char type, t_flags flags);
char	*parse_zero(char *str, char is_neg, t_flags flags);
char	*parse_width(char *str, t_flags flags);

#endif
