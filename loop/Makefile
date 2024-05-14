SHELL	=	/bin/sh
CC	=	gcc
RM	= 	rm -rf

MAIN	=	src/main.c

SRC	=	src/init_generation.c	\
		src/special_cases.c	\
		src/data_free.c		\
		src/dig_map.c		\
		src/curses.c		\
		src/solver.c

OBJ	=	$(addsuffix .o, $(basename $(SRC)))

LDFLAGS	=	-l curses
CFLAGS =	-Wall -Wextra
CPPFLAGS=	-I include -I ../include

OK	=	\e[32m
RED	=	\e[91m
END	=	\e[0m

NAME	=	loop
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
	echo -e "$(OK)[DONE]\t$(NAME)$(END)" || \
	echo -e "$(RED)[FAILURE]\t$(NAME)$(END)"

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $< && \
	echo -e "$(OK)[OK]\t$<$(END)" || \
	echo -e "$(RED)[FAILURE]\t$<$(END)"

.PHONY: $(PHONY)
