# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 ??:??:?? by hdeniz            #+#    #+#              #
#    Updated: 2025/01/28 ??:??:?? by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************** [v] VARIABLES [v] ***************************** #
GL_DIRECTORY = "../../GL/"
CC = gcc
NAME = main
MAIN = main.c
MAIN_O = $(NAME).o
CFLAGS = -I$(GL_DIRECTORY)include -L$(GL_DIRECTORY)lib \
	-lglfw -lGL -lGLU -lglut -lm -ldl -lglad
# **************************** [^] VARIABLES [^] ***************************** #

# ****************************** [v] COLORS [v] ****************************** #
	C_RESET	= \033[0m
	C_BLINK	= \033[5m
	F15		= \033[38;5;15m
	B1F11	= \033[48;5;1m\033[38;5;11m
	B12F15	= \033[48;5;12m\033[38;5;15m
	B1F15	= \033[48;5;1m\033[38;5;15m
	B2F15	= \033[48;5;2m\033[38;5;15m
	F11		= \033[38;5;11m
	F13		= \033[38;5;13m
	F14		= \033[38;5;14m
	F10		= \033[38;5;10m
# ****************************** [^] COLORS [^] ****************************** #

all: gl $(MAIN_O)

$(MAIN_O):
	@$(CC) $(MAIN) -o $(NAME) $(CFLAGS) 2>/dev/null && \
		echo "\n $(C_BLINK)$(B2F15) $(NAME) is ready! $(C_RESET)\n" || \
		echo "\n $(B1F15) Failed to compile $(NAME)! $(C_RESET)\n"
gl:
	@cd $(GL_DIRECTORY) && make --no-print-directory

glfc: glc
glc:
	@cd $(GL_DIRECTORY) && make --no-print-directory fc

c: fc
clean: fc
clear: fc
fclean: fc
fclear: fc
fc:
	@rm -rf $(NAME)
	@rm -rf $(MAIN_O)

.PHONY: all c clean clear fclean fclear fc gl
