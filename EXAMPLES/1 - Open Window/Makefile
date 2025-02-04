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

# ****************************** [v] SOURCE [v] ****************************** #
SRC	=	./create_window.c
# ****************************** [^] SOURCE [^] ****************************** #

# **************************** [v] VARIABLES [v] ***************************** #
	# [COMPILER]
		CC = gcc
	# [COMPILER]

	GL_DIRECTORY = "../../GL/"

	# [EXE]
		NAME = main
		MAIN = main.c
	# [EXE]

	# [COMPILER FLAGS]
		CFLAGS = -I$(GL_DIRECTORY)include -L$(GL_DIRECTORY)lib \
			-lglfw -lGL -lGLU -lglut -lm -ldl -lglad
	# [COMPILER FLAGS]

	# [.c STRINGS TO .o]
		OBJ	=	$(SRC:.c=.o)
	# [.c STRINGS TO .o]

	# ANIMATION VARIABLES
		TERMINAL_LEN	:=	\
			$(eval TERMINAL_LEN := $(shell tput cols))$(TERMINAL_LEN)
		NUMBER_OF_FILES	:=	0
		FILE_COUNTER	:=	0
		N_OBJ			:=	$(eval N_OBJ := $$(shell find . \
		-name '*.o' -type f | wc -w | sed "s/ //g" | bc))$(N_OBJ)
	# ANIMATION VARIABLES
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

# ***************************#* [v] FUNCIONS [v] ***************************** #
define progress_bar
	$(eval PBAR := $(shell echo $(1)*100/$(2)*100/100 | bc))
	$(eval PDONE := $(shell echo $(PBAR)*3/10 | bc))
	$(eval PLEFT := $(shell echo 30-$(PDONE) | bc))
	$(eval PSEQ := $(shell seq 0 1 $(PLEFT) 2>/dev/null))
	$(eval PEMPTY := $(shell if [ "$(1)" -ne "$(2)" ]; \
		then printf ".%.0s" $(PSEQ); fi))
	$(eval PFILL := $(shell printf "\#%.0s" $(shell seq 1 $(PDONE))))
	@printf "\r%*s\r $(F11)[$(F14)$(PFILL)$(PEMPTY)$(F11)] $(PBAR)%% - \
		$(F10)[$(1)/$(2)]$(F11) [$(F13)$(3)$(F11)$(C_RESET)]" \
		$(TERMINAL_LEN) " "
endef
# ***************************#* [^] FUNCIONS [^] ***************************** #

%.o: %.c
	$(eval NUMBER_OF_FILES := $(shell echo $(SRC) \
		| wc -w | sed "s/ //g" | bc))
	$(eval NUMBER_OF_FILES := $(shell echo $(NUMBER_OF_FILES) - $(N_OBJ) | bc))
	$(if $(filter 0,$(NUMBER_OF_FILES)), $(eval NUMBER_OF_FILES := 1))
	$(eval FILE_COUNTER := $(shell echo $(FILE_COUNTER) + 1 | bc))
	$(call progress_bar,$(FILE_COUNTER),$(NUMBER_OF_FILES),$<)
	@rm -f $(NAME) 2>/dev/null
	@$(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null || (\
		echo "\n\n $(B1F15) Failed to compile [$(F11)$<$(F15)] $(C_RESET)\n" \
		&& $(CC) $(CFLAGS) -c $< -o $@)

all: $(NAME)

$(NAME): gl $(MAIN) $(OBJ)
	@$(CC) $(MAIN) -o $(NAME) $(OBJ) $(CFLAGS) && \
		echo "\n $(C_BLINK)$(B2F15) $(NAME) is ready! $(C_RESET)\n" || \
		echo "\n $(B1F15) Failed to compile $(NAME)! $(C_RESET)\n"
gl:
	@cd $(GL_DIRECTORY) && make --no-print-directory

cgl: glc
fcgl: glc
glfc: glc
glc:
	@cd $(GL_DIRECTORY) && make --no-print-directory fc

clean: c
clear: c
c:
	@rm $(OBJ) 2>/dev/null && \
		echo "\n $(B1F15) Objects are cleared! $(C_RESET)\n" || \
		echo "\n $(B12F15) Nothing to clear! $(C_RESET)\n"
	$(eval N_OBJ := "0")

fclean: fc
fclear: fc
fc: c
	@rm $(NAME) 2>/dev/null && \
		echo "\n $(B1F11) $(MAIN_EXE) $(F15)deleted! $(C_RESET)\n" || \
		echo "\n $(B12F15) $(MAIN_EXE) is not exist already! $(C_RESET)\n"

re: fc all

.PHONY: all c clean clear fclean fclear fc gl glfc glc cgl fcgl re
