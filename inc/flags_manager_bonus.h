/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manager_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:06:54 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/24 10:07:19 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_MANAGER_BONUS_H
# define FLAGS_MANAGER_BONUS_H

# include "libft.h"

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

#endif
