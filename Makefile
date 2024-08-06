NAME = pipex

SRCS = mandatory/pipex.c mandatory/utils.c
OBJS = ${SRCS:.c=.o}

SRCS_B = bonus/pipex_bonus.c bonus/utils_bonus.c bonus/utils_extra_bonus.c
OBJS_B = ${SRCS_B:.c=.o}

HEADER = -Iincludes	

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

GNL_DIR = get_next_line/
GNL = $(GNL_DIR)get_next_line.a

PRINTF_DIR = ft_printf/
PRINTF = $(PRINTF_DIR)ft_printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(PRINTF)
	$(CC) $(OBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(PRINTF_DIR) -lftprintf -o $(NAME)

bonus: $(OBJS_B) $(LIBFT) $(GNL) $(PRINTF)
	$(CC) $(OBJS_B) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl -L$(PRINTF_DIR) -lftprintf -o $(NAME)

$(LIBFT) $(GNL) $(PRINTF): FORCE
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(PRINTF_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

re_bonus: fclean bonus

FORCE:

.PHONY: all bonus clean fclean re re_bonus
