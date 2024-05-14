SHELL	=	/bin/sh

RM	=	rm -rf

OK	=	\e[32m

FAIL	=	\e[91m

PHONY	:=	all

TXT_SIZE=	20

SRC_T	=	tests/unit_tests.c

OBJ_T	=	$(addsuffix .o, $(basename $(SRC_T)))

OBJ	=	obj/*.o

LDFLAGS	=	--coverage -l criterion

CPPFLAGS=	-I "include/"

CFLAGS	=	--coverage -l criterion

T_NAME	=	unit_tests

DEBUG	=	0

NAME	=	Root

define center_text
	printf "\e[92m";
	$(SHELL) -c "printf '=%.0s' \
	{1..$$(($(TXT_SIZE) - $$(awk 'BEGIN{print length("$1")}') / 2))}";
	printf '%s' "$1";
	$(SHELL) -c "printf '=%.0s' \
	{1..$$(($(TXT_SIZE) - $$(awk 'BEGIN{print length("$1")}') / 2 - \
	$$[$$(($$(($$(awk 'BEGIN{print length("$1")}') / 2)) * 2))!=\
	$$(awk 'BEGIN{print length("$1")}')]))}";
	echo -e "\e[0m";
endef

all:
	@$(MAKE) -s -C solver DEBUG=$(DEBUG)
	@$(MAKE) -s -C generator DEBUG=$(DEBUG)
	@$(MAKE) -s -C loop DEBUG=$(DEBUG)

%.o: %.c
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $< && \
	echo -e "$(OK)[OK]\t$<\e[0m" || \
	(echo -e "$(FAIL)[FAILURE]\t$<\e[0m")

PHONY += rm_prompt
rm_prompt:
	@$(call center_text,Clean)

PHONY += tclean
tclean: rm_prompt
	@find ./ -name "*.gcno" -delete -o -name "*.gcda" -delete
	@$(RM) $(T_NAME)
	@echo -e "\e[91mTests : Cleaned gc** and ./$(T_NAME).\e[0m"

PHONY += clean
clean: rm_prompt
	@find . -name "*.o" -delete
	@echo -e "\e[91m$(NAME) : Removed object files.\e[0m"

PHONY += fclean
fclean: rm_prompt
	@find . -name "*.o" -delete
	@$(RM) solver/solver generator/generator loop/loop
	@echo -e "\e[91m$(NAME) : Removed object files and binaries.\e[0m"

PHONY += lclean
lclean: rm_prompt

PHONY += fltclean
fltclean: fclean lclean tclean

PHONY += flclean
flclean: fclean lclean

PHONY += re
re: fltclean all

.PHONY: $(PHONY)