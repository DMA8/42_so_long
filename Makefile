# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syolando <syolando@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 15:37:09 by syolando          #+#    #+#              #
#    Updated: 2022/03/08 18:50:59 by syolando         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMEB = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX = libmlx*
OBJDIR = obj
OBJDIRB = obj_bonus

SRCDIR = src
LIBDIR = libft/
GNLDIR = $(SRCDIR)/gnl

HEADER = so_long.h
HEADERB = so_long_bonus.h

MLX = libmlx*
LIBFT = libft.a

SRC =	main.c \
		$(GNLDIR)/get_next_line.c	\
		$(GNLDIR)/get_next_line_utils.c	\
		$(SRCDIR)/utils.c	\
		$(SRCDIR)/valid_map_utils.c	\
		$(SRCDIR)/constuctors.c	\
		$(SRCDIR)/valid_map.c	\
		$(SRCDIR)/hooks.c	\
		$(SRCDIR)/images.c	\
		$(SRCDIR)/check_textures.c	\


SRCB =	main_bonus.c \
		$(GNLDIR)/get_next_line.c	\
		$(GNLDIR)/get_next_line_utils.c	\
		$(SRCDIR)/utils_bonus.c	\
		$(SRCDIR)/valid_map_utils_bonus.c	\
		$(SRCDIR)/constuctors_bonus.c	\
		$(SRCDIR)/valid_map_bonus.c	\
		$(SRCDIR)/hooks_bonus.c	\
		$(SRCDIR)/images_bonus.c	\
		$(SRCDIR)/animate_bonus.c	\
		$(SRCDIR)/check_textures_bonus.c	\

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
OBJB = $(addprefix $(OBJDIR)/, $(SRCB:.c=.o))

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus	:	$(OBJB)
			@make -C $(LIBDIR)/
			@cp $(LIBDIR)/$(LIBFT) ./
			@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJB) $(LIBFT) -o $(NAMEB)

$(OBJDIR)/%.o:	%.c $(HEADER) $(HEADERB) Makefile
				$(CC) $(CFLAGS) -Imlx -c $< -o $@
$(OBJDIR)/$(SRCDIR)/%.o: 	$(SRCDIR)/%.c $(HEADER) $(HEADERB) Makefile
				$(CC) $(CFLAGS) -Imlx -c $< -o $@
$(OBJDIR)/$(SRCDIR)/gnl/%.o: 	$(SRCDIR)/gnl/%.c
					$(CC) $(CFLAGS) -Imlx -c $< -o $@
$(OBJDIR) :
				@mkdir $@ $@/$(SRCDIR) $@/$(SRCDIR)/gnl

$(OBJ) : | $(OBJDIR)
$(OBJB) : | $(OBJDIR)

clean:
	@make fclean -C $(LIBDIR)/
	@rm -rf $(OBJDIR)
	
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAMEB)
	@rm -f $(LIBFT)
	
re: fclean all
.PHONY	:	all bonus clean fclean re
