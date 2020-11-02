UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	SHELL				=	/bin/zsh
endif

# Executable name
NAME				=	ft_ssl

# Compilation mode
WALL				=	yes
WEXTRA				=	yes
WERROR				=	yes

FSANITIZE			=	no
DEBUG				=	yes
O2					=	no

ifeq ($(UNAME), Linux)
	CC					:=	gcc -lm
else
	CC					:=	gcc
endif
GEN					:=	"Generation in mode"

ifeq ($(WALL), yes)
	CC				:=	$(CC) -Wall
	GEN				:=	$(GEN) all
endif

ifeq ($(WEXTRA), yes)
	CC				:=	$(CC) -Wextra
	GEN				:=	$(GEN) extra
endif

ifeq ($(WERROR), yes)
	CC				:=	$(CC) -Werror
	GEN				:=	$(GEN) error
endif

ifeq ($(WEVERYTHING), yes)
	CC				:=	$(CC) -Weverything
	GEN				:=	$(GEN) all
endif

ifeq ($(FSANITIZE), yes)
	CC				:=	$(CC) -fsanitize=address
	GEN				:=	$(GEN) sanitize
endif

ifeq ($(DEBUG), yes)
	CC				:=	$(CC) -g3
	GEN				:=	$(GEN) debug
endif

ifeq ($(O2),yes)
	CC				:=	$(CC) -O2
	GEN				:=	$(GEN) O2
endif

ifeq ($(GEN), "Generation in mode")
	GEN				:=	$(GEN) no flags
endif

# Text format
_DEF				=	$'\033[0m
_END				=	$'\033[0m
_GRAS				=	$'\033[1m
_SOUL				=	$'\033[4m
_CLIG				=	$'\033[5m
_SURL				=	$'\033[7m

# Colors
_BLACK				=	$'\033[30m
_RED				=	$'\033[31m
_GREEN				=	$'\033[32m
_YELLOW				=	$'\033[33m
_BLUE				=	$'\033[34m
_PURPLE				=	$'\033[35m
_CYAN				=	$'\033[36m
_GREY				=	$'\033[37m

# Background
_IBLACK				=	$'\033[40m
_IRED				=	$'\033[41m
_IGREEN				=	$'\033[42m
_IYELLOW			=	$'\033[43m
_IBLUE				=	$'\033[44m
_IPURPLE			=	$'\033[45m
_ICYAN				=	$'\033[46m
_IGREY				=	$'\033[47m

SRC_NAME =			openssl.c					\
					ft_parsing.c				\
					ft_tools.c					\
					ft_print.c					\
					md5/ft_md5.c				\
					md5/ft_init_md5.c			\
					md5/ft_tools.c				\
					sha224/ft_sha224.c			\
					sha256/ft_sha256.c			\
					sha256/ft_tools_sha256.c	\
					sha256/ft_init_sha256.c		\
					sha384/ft_sha384.c			\
					sha512/ft_sha512.c			\
					sha512/ft_tools_sha512.c	\
					sha512/ft_init_sha512.c		\


SRC_PATH =			./src/

OBJ_PATH =			./obj/

INC_PATH =			./include/

INC_NAME =			ft_md5.h					\
					ft_sha224.h					\
					ft_sha256.h					\
					ft_sha384.h					\
					ft_sha512.h					\


LIBFT				=	./libft/
LIBFT_NAME			=	libft.a
LIBFTINCLUDES		=	./libft/

INC	= $(addprefix $(INC_PATH), $(INC_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

.PHONY :	all clean fclean re

all: $(NAME)

$(LIBFT)/$(LIBFT_NAME):
	@make -C $(LIBFT) -j
	@echo "$(_GREEN)[ LIBFT DONE ]$(_END)"

$(NAME) : $(LIBFT)/$(LIBFT_NAME) $(OBJ)
		@mkdir -p $(OBJ_PATH)
		@echo "\n$(_WHITE)====================================================$(_END)"
		@echo "$(_YELLOW)		COMPILING $(NAME)$(_END)"
		@echo "$(_WHITE)====================================================$(_END)"
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)/$(LIBFT_NAME) -lm
		@echo "\n$(_WHITE)$(_BOLD)$@\t$(_END)$(_GREEN)[OK]\n$(_END)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)md5/
	@mkdir -p $(OBJ_PATH)sha224/
	@mkdir -p $(OBJ_PATH)sha256/
	@mkdir -p $(OBJ_PATH)sha384/
	@mkdir -p $(OBJ_PATH)sha512/
	@$(CC) -I $(INC_PATH) -I $(LIBFTINCLUDES) -c $< -o $@
	@echo "$(_END)$(_GREEN)[OK]\t$(_UNDER)$(_YELLOW)\t"	\
		"COMPILE :$(_END)$(_BOLD)$(_WHITE)\t$<"

clean:
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(OBJ_PATH)"$(_END)"
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME)
	@rm -f $(LIBFT)$(LIBFT_NAME)
	@echo "$(_YELLOW)Remove :\t$(_RED)" $(LIBFT)$(LIBFT_NAME)"$(_END)"

re : fclean all