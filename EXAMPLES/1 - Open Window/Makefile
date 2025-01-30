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

GL_DIRECTORY = "../../GL/"
MAIN = main
MAIN_C = main.c
MAIN_O = main.o
CFLAGS = -I$(GL_DIRECTORY)include -L$(GL_DIRECTORY)lib \
	-lglfw -lGL -lGLU -lglut -lm -ldl -lglad

all: gl $(MAIN_O)

$(MAIN_O):
	gcc $(MAIN_C) -o $(MAIN) $(CFLAGS)

gl:
	@cd $(GL_DIRECTORY) && make

glfc: glc
glc:
	@cd $(GL_DIRECTORY) && make fc

c: fc
clean: fc
clear: fc
fclean: fc
fclear: fc
fc:
	@rm -rf $(MAIN)

.PHONY: all c clean clear fclean fclear fc gl
