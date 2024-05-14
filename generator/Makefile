SHELL	=	/bin/sh
CC	=	gcc
MAIN	=	src/main.c

SRC	=	src/init_generation.c	\
		src/special_cases.c	\
		src/print_output.c	\
		src/data_free.c		\
		src/dig_map.c

OBJ	=	$(addsuffix .o, $(basename $(SRC)))

LDFLAGS	=
CFLAGS =	-Wall -Wextra
CPPFLAGS=	-I "../include/"

OK	=	\e[32m
FAIL	=	\e[91m

NAME	=	generator

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
	$(eval OBJ += $(MAIN:.c=.o))
	@$(MAKE) -s $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	echo -e "$(OK)[DONE]\t$(NAME)\e[0m" || \
	(echo -e "$(FAIL)[FAIL]\t$(NAME)\e[0m"; $(MAKE) -s fclean)

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $< && \
	echo -e "$(OK)[OK]\tgenerator/$<\e[0m" || \
	(echo -e "$(FAIL)[FAIL]\tgenerator$<\e[0m")

.PHONY: $(PHONY)
