# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:09:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/02/20 19:05:55 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library
NAME	=	libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR) -MMD -MP
DEBUG	=	-g -fsanitize=address

# Directories
INC_DIR		=	inc
LIBFT_DIR	=	libft
SRC_DIR		=	src
OBJ_DIR		=	obj

LIBFT = $(LIBFT_DIR)/libft.a

# Headers #TODO
INCLUDES	=	$(INC_DIR)/ft_printf.h $(INC_DIR)/ft_printf_bonus.h \
				#$(INC_DIR)/write_types.h \
				$(INC_DIR)/utils.h \
				$(INC_DIR)/libft.h \
				$(INC_DIR)/ft_printf_bonus.h \
				$(INC_DIR)/flags_manager_bonus.h \
				$(INC_DIR)/write_types_bonus.h \
				$(INC_DIR)/parse_flags_bonus.h \
				$(INC_DIR)/parse_types_bonus.h \
				$(INC_DIR)/parse_precision_bonus.h

SRCS		=	ft_printf.c write_types.c #utils.c
SRCS_BONUS	=	ft_printf_bonus.c write_types_bonus.c \
			flags_manager_bonus.c parse_types_bonus.c parse_precision_bonus.c \
			parse_flags_bonus.c

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS	=	$(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))
OBJS_ALL	=	$(OBJS) $(OBJS_BONUS)

# Colors
GREEN		=	\033[0;32m
GREEN_BOLD	=	\033[1;32m
RED			=	\033[0;31m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
CYAN		=	\033[0;36m
PURPLE		=	\033[0;35m
RESET		=	\033[0m

ifneq ($(filter debug debug_bonus, $(MAKECMDGOALS)),)
	COLOR	=	$(YELLOW)
else
	COLOR	=	$(GREEN)
endif

# Targets
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)📂 Created directory: $(OBJ_DIR) $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR)Compiled: $< $(RESET)"

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN_BOLD)Library built: $(NAME) $(RESET)"
	
FORCE:

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "$(CYAN)🧹 Cleaned object files 🧹 $(RESET)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(CYAN)🧹 Cleaned object files 🧹 $(RESET)"
	@echo "$(CYAN)🧹 Cleaned library 🧹 $(RESET)"

re: fclean all

.bonus: $(OBJS_BONUS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@touch $@
	@ar rcs $(NAME) $(OBJS_BONUS)
	@echo "$(GREEN_BOLD)Library built: $(NAME) $(RESET)"

bonus: .bonus

# --------------------------------------------


norm:
	norminette $(SRCS) $(LIBFT_DIR) $(INCLUDES) $(SRCS_BONUS)

.PHONY: all clean fclean re norm bonus FORCE

-include $(OBJS_ALL:.o=.d)
