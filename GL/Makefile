# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 ??:??:?? by hdeniz            #+#    #+#              #
#    Updated: 2025/01/30 ??:??:?? by hdeniz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FREE_GLUT = ./lib/libglut.a
GLFW = ./lib/libglfw3.a
GLAD = ./lib/libglad.a

FREE_GLUT_REPO = https://github.com/FreeGLUTProject/freeglut.git
GLFW_REPO = https://github.com/glfw/glfw.git

all: folders $(GLAD) $(FREE_GLUT) $(GLFW)

folders:
	@mkdir -p ./lib
	@mkdir -p ./src
	@mkdir -p ./include

$(FREE_GLUT):
	@if [ ! -d "./src/GLUT" ]; then \
		git clone --depth 1 --branch v3.2.2 $(FREE_GLUT_REPO) ./src/GLUT; \
	fi
	@cd ./src/GLUT && \
	cmake -S . -B build -DCMAKE_INSTALL_PREFIX=../../ && \
	cmake --build build && \
	cmake --install build --prefix ../../

$(GLFW):
	@if [ ! -d "./src/GLFW" ]; then \
		git clone --depth 1 --branch 3.3 $(GLFW_REPO) ./src/GLFW; \
	fi
	@cd ./src/GLFW && \
	cmake -S . -B build -DCMAKE_INSTALL_PREFIX=../../ && \
	cmake --build build && \
	cmake --install build --prefix ../../

$(GLAD):
	@gcc -c "./src/glad.c" -o $(GLAD) -Iinclude -ldl -lGL

c: fc
clean: fc
clear: fc
fclean: fc
fclear: fc
fc:
	@rm -rf $(FREE_GLUT)
	@rm -rf $(GLFW)
	@rm -rf $(GLAD)
	@rm -rf ./lib
	@rm -rf ./include/GLFW
	@rm -rf ./include/GL
	@rm -rf ./src/GLUT
	@rm -rf ./src/GLFW

.PHONY: all c clean clear fclean fclear fc
