# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 06:27:55 by sklepper          #+#    #+#              #
#    Updated: 2018/10/01 09:50:46 by sklepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	fdf
SRC			:=	event.c lines_img.c main.c  \
				map.c parser.c
HEADERS		:=	fdf.h
# directories :
SRCDIR  	:=	srcs
OBJDIR 		:=	objs
INCDIR  	:=	includes
# LIBFT
LIBFT_NAME	:=	libft.a
LIBFT_PATH	:=	libft/
LIBFT_INC	:=	includes
# **************************************************************************** #
# Run config :
MAP			:=	maps/42.fdf
# make specs :
MYCC		:=	clang
MYCC		+=	-Werror -Wall -Wextra
DEBUGCC		:=	-ggdb -fsanitize=address
RM			:=	/bin/rm -f
# **************************************************************************** #
# Automatic variable :
OBJ			:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEAD		:=	$(addprefix $(INCDIR)/, $(HEADERS))
# Includes :
INCF_FDF	:=	$(INCDIR)
INCF_LIBFT	:=	$(LIBFT_PATH)$(LIBFT_INC)
# Lib link :
LINKF_LIBFT	:=	$(LIBFT_PATH)$(LIBFT_NAME)
# Framework :
FRAME_W		:=	-framework OpenGL -framework AppKit
LIB			:=	-L $(LIBFT_PATH) -lft -L /usr/local/lib -lmlx
INC			:=	-I$(INCF_LIBFT) -I$(INCF_LMLX) -I$(INCDIR)
# **************************************************************************** #
# Target rules :
all: $(NAME)
$(NAME): $(OBJ) $(LINKF_LIBFT) $(HEAD)
	@$(MYCC) -o $@ $(OBJ) $(INC) $(LIB) $(FRAME_W)
	@chmod -r $(NAME)
$(LINKF_LIBFT):
	@make -C $(LIBFT_PATH)/

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(MYCC) $(CFLAG) $(INC) -o $@ -c $<
clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJDIR) 2> /dev/null || true
lclean:
	@make -C $(LIBFT_PATH)/ clean
fclean: clean lclean
	@make -C $(LIBFT_PATH)/ fclean
	@$(RM) $(NAME)
re: fclean all
debug : clean $(OBJ) $(LINKF_LIBFT) $(LINKF_LMLX)
	@$(MYCC) $(DEBUGCC) -o $(NAME) $(OBJ) $(INC) $(LIB) $(FRAME_W)
run: debug
	# @cat $(MAP)
	@./$(NAME) $(MAP)
git: fclean
	@git add -A
	@git status
.PHONY: all, $(NAME), clean, fclean, re, debug, run, git
