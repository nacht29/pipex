NAME = pipex

SRCS = mandatory/pipex.c mandatory/utils.c
OBJS = ${SRCS:.c=.o}

SRCS_B = bonus/pipex_bonus.c bonus/utils_bonus.c bonus/utils_extra_bonus.c
OBJS_B = ${SRCS_B:.c=.o}

HEADER = -Iincludes

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@
# @echo "$(GREEN)pipex object files$(RESET)"
# cc -Wall -Wextra -Werror -Iincludes -c mandatory/pipex.c -o mandatory/pipex.o
# cc -Wall -Wextra -Werror -Iincludes -c mandatory/utils.c -o mandatory/utils.o

GREEN = \033[1;32m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
AQUA = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo ""
	@echo "$(AQUA)pipex executable programme compiled$(RESET)"
# cc mandatory/pipex.o mandatory/utils.o -Llibft/ -lft -o pipex

bonus: $(OBJS_B) $(LIBFT)
	@$(CC) $(OBJS_B) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo ""
	@echo "$(AQUA)(bonus)pipex executable programme compiled$(RESET)"

$(LIBFT): FORCE
	@echo ""
	@echo "$(YELLOW)compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS) $(OBJS_B)
	@echo "$(PURPLE)clean successful$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(PURPLE)fclean successful$(RESET)"

re: fclean all

re_bonus: fclean bonus

FORCE:

.PHONY: all bonus clean fclean re re_bonus
