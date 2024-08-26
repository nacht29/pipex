NAME = libft.a

SRC = $(wildcard */*.c)
  
OBJS = $(SRC:.c=.o)

GNL_DIR = get_next_line/
GNL = get_next_line.a

PRINTF_DIR = ft_printf/
PRINTF = ft_printf.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[1;32m
RESET = \033[0m

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(GNL) $(PRINTF) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ar -q $(NAME) $(GNL_DIR)*.o
	@ar -q $(NAME) $(PRINTF_DIR)*.o
	@echo "$(GREEN)libft compiled$(RESET)"

$(GNL):
	@make -C $(GNL_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	@$(RM) $(OBJS)
	@make -C $(GNL_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@$(RM) $(NAME) $(GNL) $(PRINTF)
	@make -C $(GNL_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re