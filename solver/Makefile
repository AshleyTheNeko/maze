SHELL	=	/bin/sh
CC	=	gcc

MAIN	=	src/execute_solver/main.c

SRC	=	src/error_handling/error_handling.c	\
		src/error_handling/check_content.c	\
		src/execute_solver/init_infos.c		\
		src/utils/display_elements.c		\
		src/execute_solver/solver.c		\
		src/execute_solver/free.c		\
		src/utils/convert_map.c			\
		src/utils/open_file.c

OBJ	=	$(addsuffix .o, $(basename $(SRC)))

LDFLAGS	=
CFLAGS 	=	-Wall -Wextra
CPPFLAGS=	-I "../include/"

OK		=	\e[32m
FAIL	=	\e[91m

NAME	=	solver
PHONY	:=	all
DEBUG	=	0

define center_text
	echo -e "$(OK)>>>>\t$1$(END)"
endef

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(SRC) $(MAIN)
	@$(call center_text,$(NAME))
	@$(eval OBJ += $(MAIN:.c=.o))
	@$(MAKE) -s $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(OK)[DONE]\t$(NAME)\e[0m" || \
	(echo -e "$(FAIL)[FAIL]\t$(NAME)\e[0m")

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $< && \
	echo -e "$(OK)[OK]\tsolver/$<\e[0m" || \
	(echo -e "$(FAIL)[FAIL]\tsolver/$<\e[0m")

.PHONY: $(PHONY)